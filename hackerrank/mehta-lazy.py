def rwh_primes1(n):
	sieve = [True] * (n/2)
	for i in xrange(3,int(n**0.5)+1,2):
		if sieve[i/2]:
			sieve[i*i/2::i] = [False] * ((n-i*i-1)/(2*i)+1)
	return [2] + [2*i+1 for i in xrange(1,n/2) if sieve[i]]
def is_square(n):
	return sqrt(n).is_integer()
from fractions import gcd
from math import sqrt
primes = rwh_primes1(1000);
t = input()
for i in xrange(t):
	n = input();
	div = {}
	j = 0;
	rn = n;
	while n > 1 and j < len(primes):
		no = 0;
		while n%primes[j] == 0:
			n /= primes[j];
			no+=1;
		if no != 0:
			div[primes[j]] = no;
		j+=1
	if n!= 1:
		div[n] = 1;
	num = 1;
	den = 1;
	if 2 not in div.keys():
		print 0
	elif div[2] == 1:
		print 0
	else:
		num = div[2]/2;
		for k in div.keys():
			if k == 2:
				den = den*(div[k]+1);
				continue;
			num = num*(div[k]/2 +1)
			den = den*(div[k]+1);
		den -=1
		if is_square(rn):
			num -=1
		# print div
		# print num
		gd = gcd(num,den)
		st = str(num/gd)+"/"+str(den/gd)
		print st