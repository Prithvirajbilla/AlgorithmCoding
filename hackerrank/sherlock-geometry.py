t = input()
def giv(xc,yc,x1,y1,r):
	return (xc-x1)**2 + (yc-y1)**2 - r**2;
for i in xrange(t):
	l = [int(k) for k in raw_input().strip().split()]
	xc = l[0];yc = l[1];r =l[2];
	l = [int(k) for k in raw_input().strip().split()]
	x1 = l[0];y1 = l[1];
	l = [int(k) for k in raw_input().strip().split()]
	x2 = l[0];y2 = l[1];
	l = [int(k) for k in raw_input().strip().split()]
	x3 = l[0];y3 = l[1];

	r1 = giv(xc,yc,x1,y1,r);
	r2 = giv(xc,yc,x2,y2,r);
	r3 = giv(xc,yc,x3,y3,r);
	li = [r1,r2,r3]
	number = 0;
	for k in li:
		if k <= 0:
			number+=1;
	if number == 0:
		print "NO"
	elif number <= 2:
		print "YES"
	else:
		print "NO"


