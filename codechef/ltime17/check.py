n = input()
for i in xrange(0,n+1):
	for j in xrange(0,n+1):
		k = n-i-j;
		if j&i == j and k&j == k:
			print i,j,k
