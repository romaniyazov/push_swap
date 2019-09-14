from graphics import *
from sys import argv
from time import sleep

a = [num for num in argv]
a.pop(0)
a = [int(num) for num in a]
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
win = GraphWin('push_swap', len_a, max(a) * 2, autoflush=False)
win.flush()
inp = True
s = False
text = False
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
	text = Text(Point(20, 5), inp).draw(win)
	for x in range(len_a):
		aol[x] = al[x]
		bol[x] = bl[x]
	x = 0
	for num in a:
		al[x] = Line(Point(x, len_a), Point(x, len_a - num))
		x += 1
	while x < len_a:
		al[x] = 0
		x += 1
	x = 0
	for num in b:
		bl[x] = Line(Point(x, len_a * 2), Point(x, len_a * 2 - num))
		x += 1
	while x < len_a:
		bl[x] = 0
		x += 1
	for x in range(len_a):
		if al[x] != aol[x]:
			if aol[x] != 0: aol[x].undraw()
			if al[x] != 0: al[x].draw(win)
		if bl[x] != bol[x]:
			if bol[x] != 0: bol[x].undraw()
			if bl[x] != 0: bl[x].draw(win)
	win.flush()
sleep(10)
print(a)
print(b)