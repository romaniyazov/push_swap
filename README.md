![push_swap](https://raw.githubusercontent.com/romaniyazov/push_swap/master/readme_assets/readme_title.png)

The goal of this project is to sort numbers on a stack using one auxillary
stack with a limited set of instructions. Numbers given as arguments get loaded
to the first stack.

As a result, the first stack must be sorted and the second stack must be empty.

### push_swap program

Push_swap takes a list of numbers as arguments and prints out a list of
instructions.

#### Instructions

| Code | Name             | Description |
|------|------------------|-------------|
| sa   | swap a           |             |
| sb   | swap b           |             |
| ss   | sa & sb          |             |
| ra   | rotate a         |             |
| rb   | rotate b         |             |
| rr   | ra & rb          |             |
| rra  | reverse rotate a |             |
| rrb  | reverse rotate b |             |
| rrr  | rra & rrb        |             |

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

### Visualizer
Visuzlizer is written in python3 and uses graphics.py
(`pip3 install graphics.py`). It takes a list of numbers as argument and  reads
instructions from stdin, same as checker.
```
$> ./push_swap $ARG | ./visu $ARG
```

![visualizer](https://raw.githubusercontent.com/romaniyazov/push_swap/master/readme_assets/visualizer.png)
