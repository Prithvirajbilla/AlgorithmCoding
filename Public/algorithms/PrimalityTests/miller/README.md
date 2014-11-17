Rabin-Miller primality test
===========================

Let n be a prime number greater than 2. then n-1 is an even number. we can write n-1 as 2^r*d where d is an odd number.
then for a belongs to N;
<pre><code>
a^d == 1 (mod n)
or 
a^(2^k * d) == -1 (mod n)
k belongs to the {1, .. r}
</code></pre>