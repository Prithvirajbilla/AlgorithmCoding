[l1,u1] = [int(k) for k in raw_input().strip().split(",")]
[l2,u2] = [int(k) for k in raw_input().strip().split(",")]
[l3,u3] = [int(k) for k in raw_input().strip().split(",")]
import math
def f(a,b,c):
	k = abs(a-b)
	return math.sqrt(k**2 + c**2)

li = []
li.append(f(l2,l3,l1));
li.append(f(l2,u3,l1));
li.append(f(l3,u2,l1));
li.append(f(u3,u2,l1));

li.append(f(l2,l3,u1));
li.append(f(l2,u3,u1));
li.append(f(l3,u2,u1));
li.append(f(u3,u2,u1));

li.sort()

# for i in xrange(l1,u1+1):
# 	for j in xrange(l2,u2+1):
# 		for k in xrange(l3,u3+1):
# 			bs = abs(k-j)
# 			val = math.sqrt(bs**2 + i**2)
# 			mi = min(mi,math.floor(val));
# 			ma = max(ma,math.ceil(val));

print str(int(li[0]))+","+str(int(li[-1]));