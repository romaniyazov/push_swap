import random
from sys import argv
import os

cnt = int(argv[1])

nums = []
while not len(nums) == cnt:
	n = random.randint(1, cnt)
	if n not in nums:
		nums.append(n)

arg = ' '.join([str(num) for num in nums])

print(arg)
