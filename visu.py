from graphics import *
from sys import argv
from time import sleep

args = [num for num in argv]
args.pop(0)
ai = [int(num) for num in args]
a = [0 for _ in range(len(ai))]
indexed = []
i = 1
while len(indexed) < len(ai):
	min = max(ai)
	for n in ai:
		if n <= min and n not in indexed:
			min = n
	a[ai.index(min)] = min
	indexed.append(min)
b = []
len_a = len(a)
aol = []
bol = []
al = []
bl = []
for _ in range(len_a):
	aol.append(0)
	bol.append(0)
	al.append(0)
	bl.append(0)
win = GraphWin('push_swap', len_a * 3, 800, autoflush=False)
win.setBackground(color_rgb(31, 36, 48))
win.update()
inp = True
s = False
text = False
cnt = 1
while inp:
	try:
		inp = str(input())
	except EOFError:
		break
	if not s:
		sleep(1)
		s = True
	if inp == 'sa': a[0], a[1] = a[1], a[0]
	if inp == 'pa': a.insert(0, b.pop(0))
	if inp == 'pb': b.insert(0, a.pop(0))
	if inp == 'ra': a.append(a.pop(0))
	if inp == 'rb': b.append(b.pop(0))
	if inp == 'rr': a.append(a.pop(0)); b.append(b.pop(0))
	if inp == 'rra': a.insert(0, a.pop(-1))
	if inp == 'rrb': b.insert(0, b.pop(-1))
	if inp == 'rrr': a.insert(0, a.pop(-1)); b.insert(0, b.pop(-1))
	if text: text.undraw()
	text = Text(Point(50, 13), str(cnt) + ': ' + inp).draw(win)
	text.setTextColor('yellow green')
	text.setFace('courier')
	text.setStyle('bold')
	text.setSize(14)
	for x in range(len_a):
		aol[x] = al[x]
		bol[x] = bl[x]
	x = 0
	for num in a:
		al[x] = Rectangle(Point(x * 3, 400), Point(x * 3 + 2, 400 - round(num / len(args) * 400)))
		x += 1
	while x < len_a:
		al[x] = 0
		x += 1
	x = 0
	for num in b:
		bl[x] = Rectangle(Point(x * 3, 800), Point(x * 3 + 2, 800 - round(num / len(args) * 400)))
		x += 1
	while x < len_a:
		bl[x] = 0
		x += 1
	for x in range(len_a):
		if al[x] != aol[x]:
			if aol[x] != 0: aol[x].undraw()
			if al[x] != 0:
				al[x].setOutline(color_rgb(255, 160, 128))
				al[x].setFill(color_rgb(255, 160, 128))
				al[x].draw(win)
		if bl[x] != bol[x]:
			if bol[x] != 0: bol[x].undraw()
			if bl[x] != 0:
				bl[x].setOutline(color_rgb(255, 160, 128))
				bl[x].setFill(color_rgb(255, 160, 128))
				bl[x].draw(win)
	if win.checkMouse(): exit
	win.update()
	cnt += 1
win.getMouse()
