l = [int(k) for k in raw_input().strip().split()]
m = l[0]
n = l[1]
array = [1]
sum_array = [1]
for i in xrange(1,m):
	array+=[(i+1)**n -sum_array[-1]]
	sum_array += [ array[-1] + sum_array[-1]]

from decimal import Decimal

ans = 0
for i in xrange(len(array)):
	ans+= (i+1)*array[i]
cc = Decimal(ans);
cc/=(m**n)
print "%0.12f" % (cc)