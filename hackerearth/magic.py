def primes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in xrange(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)/(2*i)+1)
    return [2] + [i for i in xrange(3,n,2) if sieve[i]]

primes_list = primes(500)


def dist_p(i):
	num = 0;
	for k in primes_list:
		if i >= k:
			num+=1
	return num


l = [0,1]
for i in range(3,501):
	l.append((2**(dist_p(i)-1)))

t = input()
print sum(l[:t])