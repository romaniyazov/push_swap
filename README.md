![push_swap](https://raw.githubusercontent.com/romaniyazov/push_swap/master/readme_assets/readme_title.png)

The goal of this project is to sort numbers on a stack using one auxillary
stack with a limited set of instructions. Numbers given as arguments get loaded
to the first stack.

As a result, the first stack must be sorted and the second stack must be empty.

### push_swap program

Push_swap takes a list of numbers as arguments and prints out a list of
instructions.

#### Instructions

| Code | Name             | Description                                       |
|------|------------------|---------------------------------------------------|
| sa   | swap A           | Swap the first two elements on stack A            |
| sb   | swap B           | Swap the first two elements on stack B            |
| ss   | sa & sb          |                                                   |
| ra   | rotate A         | Move the first element of stack A to bottom       |
| rb   | rotate B         | Move the first element of stack B to bottom       |
| rr   | ra & rb          |                                                   |
| rra  | reverse rotate A | Move the last element of stack A to top           |
| rrb  | reverse rotate B | Move the last element of stack B to top           |
| rrr  | rra & rrb        |                                                   |
| pa   | push to A        | Push top element of stack B to the top of stack A |
| pb   | push to B        | Push top element of stack A to the top of stack B |

#### Example
```
$> ./push_swap 3 4 2 1 5
rra
pb
ra
pb
sa
pa
ra
pa
ra
```

### checker program
Checker takes a list of number as argument and reads instructions from stdin.
It prints out OK if the instructions are correct (the first stack is sorted and
the second stack is empty) or KO otherwise.

#### Example
```
$> ./push_swap 3 4 2 1 5 | ./checker 3 4 2 1 5
OK
$> ./checker 3 4 2 1 5
sa
rb
pb
pb
KO
```

### The algorithm
The stack is being sorted using insertion sort algorithm, which is optimal
(with some optimizations) considering the stack sizes during project evaluation
(100 and 500 elements) and restrictions of only using two stacks and a limited
set of instructions.

### Visualizer
Visuzlizer is written in python3 and uses graphics.py
(`pip3 install graphics.py`). It takes a list of numbers as argument and  reads
instructions from stdin, same as checker.
```
$> ./push_swap $ARG | ./visu $ARG
```

![visualizer](https://raw.githubusercontent.com/romaniyazov/push_swap/master/readme_assets/visualizer.png)

### Useful resources
https://en.wikipedia.org/wiki/Insertion_sort

https://www.youtube.com/watch?v=ROalU379l3U

http://www.cs.colby.edu/courses/F17/cs151/graphics.pdf
