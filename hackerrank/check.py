from math import sqrt
def is_square(n):
	return sqrt(n).is_integer()
t = input()
for k in xrange(t):
	num = 0;
	l = input()
	for i in xrange(2,l):
		if l%i == 0 and is_square(i) and i%2 ==0:
			num+=1;
			# print i
	print num

