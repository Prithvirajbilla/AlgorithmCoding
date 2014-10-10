from math import sqrt
def get_v(n):
	result = sqrt(1+4*n)
	result = result/2.
	return result
# m = 10*100
# mod = m+1
t = input()
for t in xrange(t):
	n = input()
	# quot = m/n
	# rem = m%n
	res = 0
	if n-1 == 0:
		print 0.0
		continue;
	for i in xrange(1,n):
		res += (0.5+get_v(i))/n;
	print res