from graphics import *
from sys import argv
from time import sleep

def putstacklabels():
	stack_label = Text(Point(120, 20), 'A').draw(win)
	stack_label.setTextColor('yellow green')
	stack_label.setSize(18)
	stack_label = Text(Point(120, 420), 'B').draw(win)
	stack_label.setTextColor('yellow green')
	stack_label.setSize(18)

def	put_operation(op, cnt):
	s = op
	if cnt: s = str(cnt) + ': ' + s
	text = Text(Point(50, 20), s)
	text.setTextColor('yellow green')
	text.setSize(18)
	return text

def handle_op(inp, a, b, text):
	ops = ['sa', 'sb', 'ss', 'pa', 'pb', 'ra', 'rb', 'rr', 'rra', 'rrb', 'rrr']
	if inp and inp not in ops and inp:
		exit('Operation not valid')
	if inp == 'sa' and len(a) > 1:
		a[0], a[1] = a[1], a[0]
	if inp == 'sb' and len(b) > 1:
		b[0], b[1] = b[1], b[0]
	if inp == 'ss':
		if len(a) > 1:
			a[0], a[1] = a[1], a[0]
		if len(b) > 1:
			b[0], b[1] = b[1], b[0]
	if inp == 'pa' and len(b):
		a.insert(0, b.pop(0))
	if inp == 'pb' and len(a):
		b.insert(0, a.pop(0))
	if inp == 'ra' and len(a): a.append(a.pop(0))
	if inp == 'rb' and len(b): b.append(b.pop(0))
	if inp == 'rr':
		if len(a): a.append(a.pop(0))
		if len(b): b.append(b.pop(0))
	if inp == 'rra' and len(a):
		a.insert(0, a.pop(-1))
	if inp == 'rrb' and len(b):
		b.insert(0, b.pop(-1))
	if inp == 'rrr':
		if len(a) and len(b):
			a.insert(0, a.pop(-1))
			b.insert(0, b.pop(-1))

def	draw_stacks():
	for x in range(len_a):
		if al[x] != aol[x]:
			if aol[x] != 0: aol[x].undraw()
			if al[x] != 0:
				al[x].setOutline(color_rgb(255, 160, 128))
				al[x].setFill(color_rgb(255, 160, 128))
				try:
					al[x].draw(win)
				except GraphicsError:
					exit()
		if bl[x] != bol[x]:
			if bol[x] != 0: bol[x].undraw()
			if bl[x] != 0:
				bl[x].setOutline(color_rgb(255, 160, 128))
				bl[x].setFill(color_rgb(255, 160, 128))
				try:
					bl[x].draw(win)
				except GraphicsError:
					exit()

def create_stacks():
	for x in range(len_a):
		aol[x] = al[x]
		bol[x] = bl[x]
	x = 0
	for num in a:
		al[x] = Rectangle(Point(x * line_width, 400), Point(x * line_width + line_width - 1, 400 - round(num / len(args) * 400)))
		x += 1
	while x < len_a:
		al[x] = 0
		x += 1
	x = 0
	for num in b:
		bl[x] = Rectangle(Point(x * line_width, 800), Point(x * line_width + line_width - 1, 800 - round(num / len(args) * 400)))
		x += 1
	while x < len_a:
		bl[x] = 0
		x += 1

if len(argv) < 2:
	exit(0)
elif len(argv) == 2:
	args = [num for num in argv[1].split()]
else:
	args = [num for num in argv]
	args.pop(0)
if len(args) != len(set(args)):
	print('Args not valid.')
	exit()
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
if len_a < 30:
	line_width = 30
elif len_a < 50:
	line_width = 8
elif len_a < 200:
	line_width = 6
elif len_a < 400:
	line_width = 4
else:
	line_width = 2
win = GraphWin('push_swap', line_width * len_a, 800, autoflush=False)
win.setBackground(color_rgb(31, 36, 48))
putstacklabels()
win.update()
inp = True
b = []

#	Display stacks and wait for click
text = put_operation('Click!', 0)
try:
	text.draw(win)
except GraphicsError:
	exit()
create_stacks()
draw_stacks()
win.getMouse()

cnt = 1
while inp:
	try:
		inp = str(input())
	except EOFError:
		break
	handle_op(inp, a, b, text)
	text.undraw()
	text = put_operation(inp, cnt)
	try:
		text.draw(win)
	except GraphicsError:
		exit()
	create_stacks()
	draw_stacks()
	if win.checkKey() == 'Escape':
		exit()
	win.update()
	cnt += 1
text.undraw()
if a == sorted(a):
	text = put_operation('OK', cnt - 1)
else:
	text = put_operation('KO', cnt - 1)
try:
	text.draw(win)
except GraphicsError:
	exit()
try:
	while win.getKey() != 'Escape':
		pass
except GraphicsError:
	pass
exit()
