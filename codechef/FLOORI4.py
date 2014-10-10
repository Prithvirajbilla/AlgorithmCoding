from math import * 
def cal(n):
	ret_val =  {}
	for i in xrange(1,int(sqrt(n))+1):
		k = n/i;
		ret_val[k] = 1
		d = n/i - n/(i+1)
		if d != 0:
			ret_val[i] = d
	return ret_val

def get_me_power(n,m):
	m = m*30
	# result = (n*(n+1)*(2*n+1)*(3*(n**2)+3*n-1))/30 2*5*3 (3*(i**2)+3*i-1))
	result = n *(n+1);
	mod = False
	if result%30 == 0 and not mod:
		result /= 30
		mod = True
	result *= (2*n + 1);
	if mod:
		result%= m;

	if result%30 == 0 and not mod:
		result /= 30
		mod = True

	if mod:
		part = (3*((n%m)*(n%m))%m+3*n -1)
		result *= part;
		result%= m
	else:
		result *= (3*(n**2)+3*n-1);
		result /= 30
		result %= m;
	# return result
	result = n%m;
	result *= ((n%m)+1);result %= m;
	result *= (2*(n%m) + 1)%m; result %= m;
	result *= ((3*(n%m)*(n%m))%m + 3*(n%m) - 1);result %= m;
	result /= 30;
	return result

# T = input()
# for i in xrange(T):
# 	l = [int(k) for k in raw_input().strip().split()]
# 	n = l[0]
# 	m = l[1]
# 	that_dict = cal(n);
# 	s = sorted(that_dict.keys())
# 	count = 0
# 	number = n;
# 	result = 0;
# 	# print that_dict
# 	for k in s:
# 		part = get_me_power(number,m)
# 		# print part
# 		number -= that_dict[k]
# 		result += (k-count)*part;
# 		result %= m
# 		count += (k-count);
# 		# print part,result,number
# 	print result


k =  cal(8)
print k
n_dict = {}
s = sorted(k)
for i in s:
	print i,k[i]
# print n_dict
# for key, value in sorted(k.items(), key=lambda x: (-x[0])):
# 	print key, value
# 1
# 8141 100000000
