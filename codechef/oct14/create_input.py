N = 100
T = 100
import random
import string
from random import randint
print T
for i in range(T):
	print ''.join(random.choice(string.ascii_lowercase[:2]) for _ in range(N))
	print ''.join(random.choice(string.ascii_lowercase[:4]) for _ in range(N))
	print randint(1,100),randint(1,100),randint(1,10000)
