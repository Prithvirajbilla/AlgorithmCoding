import math
t = input()
for i in xrange(t):
	l = [int(k) for k in raw_input().strip().split()]
	a = l[0];b=l[1];p=l[2];
	right = a**(1./3)
	left = b**(1./3)
	right = int(math.ceil(right))
	left = int(math.floor(left))
	ans = 0
	print right,left
	for k in xrange(right,left+1):
		if ((k**3) - 1)%p == 0:
			ans+=1
	print ans
