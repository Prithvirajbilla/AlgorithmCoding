T = input()
for i in xrange(T):
	l = [int(k) for k in raw_input().strip().split()]
	x = l[0]
	y = l[1]
	if x > 0:
		if x%2 == 1:
			left = -1* (x-1)
			right = 2*x + left
			if y>= left and y<= right:
				print "YES"
				continue
	else:
		if x%2 == 0:
			left = x
			right = -1*x
			if y>= left and y<= right:
				print "YES"
				continue

	if y>0:
		if y%2 == 0:
			left = -1* y
			right = 2*y-1+left
			if x>= left and x<= right:
				print "YES"
				continue
	else:
		if y%2 == 0:
			left = y;
			right = (-y)+1
			if x>= left and x<= right:
				print "YES"
				continue
	print "NO"


