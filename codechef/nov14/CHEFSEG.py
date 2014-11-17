l2 = [1]
for i in xrange(64):
	l2.append(l2[-1]*2)

T = input()
for i in xrange(T):
	[x,k] = [int(l) for l in raw_input().strip().split()]
	ct = 0
	tk = 0
	while tk < k:
		tk+=l2[ct]
		ct+=1
	extra = k - (tk-(2**(ct-1)))
	ans = x*1.0/(2**ct)
	ans = (2*extra-1)*ans
	print "%.7f"%ans
