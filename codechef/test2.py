T = input()
for i in xrange(T):
	l = [int(k) for k in raw_input().strip().split()]
	n = l[0]
	m = l[1]
	result = 0
	for k in xrange(1,n+1):
		part = (k**4) * (n/k); part %= m
		result += part;result %= m

	print result