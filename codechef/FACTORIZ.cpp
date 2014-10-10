#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int base = 1000000000;
const int base_digits = 9;

struct bigint {
    vector<int> a;
    int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};
int primes[1000]={2,3,5,7,  11,  13,  17,  19,  23,  29 
,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71 
,  73,  79,  83,  89,  97, 101, 103, 107, 109, 113 
, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173 
, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229 
, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281 
, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349 
, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409 
, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463 
, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541 
, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601 
, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659 
, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733 
, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809 
, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863 
, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941 
, 947, 953, 967, 971, 977, 983, 991, 997,1009,1013 
,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069 
,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151 
,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223 
,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291 
,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373 
,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451 
,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511 
,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583 
,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657 
,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733 
,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811 
,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889 
,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987 
,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053 
,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129 
,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213 
,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287 
,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357 
,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423 
,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531 
,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617 
,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687 
,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741 
,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819 
,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903 
,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999 
,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079 
,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181 
,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257 
,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331 
,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413 
,3433,3449,3457,3461,3463,3467,3469,3491,3499,3511 
,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571 
,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643 
,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727 
,3733,3739,3761,3767,3769,3779,3793,3797,3803,3821 
,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907 
,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989 
,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057 
,4073,4079,4091,4093,4099,4111,4127,4129,4133,4139 
,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231 
,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297 
,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409 
,4421,4423,4441,4447,4451,4457,4463,4481,4483,4493 
,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583 
,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657 
,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751 
,4759,4783,4787,4789,4793,4799,4801,4813,4817,4831 
,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937 
,4943,4951,4957,4967,4969,4973,4987,4993,4999,5003 
,5009,5011,5021,5023,5039,5051,5059,5077,5081,5087 
,5099,5101,5107,5113,5119,5147,5153,5167,5171,5179 
,5189,5197,5209,5227,5231,5233,5237,5261,5273,5279 
,5281,5297,5303,5309,5323,5333,5347,5351,5381,5387 
,5393,5399,5407,5413,5417,5419,5431,5437,5441,5443 
,5449,5471,5477,5479,5483,5501,5503,5507,5519,5521 
,5527,5531,5557,5563,5569,5573,5581,5591,5623,5639 
,5641,5647,5651,5653,5657,5659,5669,5683,5689,5693 
,5701,5711,5717,5737,5741,5743,5749,5779,5783,5791 
,5801,5807,5813,5821,5827,5839,5843,5849,5851,5857 
,5861,5867,5869,5879,5881,5897,5903,5923,5927,5939 
,5953,5981,5987,6007,6011,6029,6037,6043,6047,6053 
,6067,6073,6079,6089,6091,6101,6113,6121,6131,6133 
,6143,6151,6163,6173,6197,6199,6203,6211,6217,6221 
,6229,6247,6257,6263,6269,6271,6277,6287,6299,6301 
,6311,6317,6323,6329,6337,6343,6353,6359,6361,6367 
,6373,6379,6389,6397,6421,6427,6449,6451,6469,6473 
,6481,6491,6521,6529,6547,6551,6553,6563,6569,6571 
,6577,6581,6599,6607,6619,6637,6653,6659,6661,6673 
,6679,6689,6691,6701,6703,6709,6719,6733,6737,6761 
,6763,6779,6781,6791,6793,6803,6823,6827,6829,6833 
,6841,6857,6863,6869,6871,6883,6899,6907,6911,6917 
,6947,6949,6959,6961,6967,6971,6977,6983,6991,6997 
,7001,7013,7019,7027,7039,7043,7057,7069,7079,7103 
,7109,7121,7127,7129,7151,7159,7177,7187,7193,7207
,7211,7213,7219,7229,7237,7243,7247,7253,7283,7297 
,7307,7309,7321,7331,7333,7349,7351,7369,7393,7411 
,7417,7433,7451,7457,7459,7477,7481,7487,7489,7499 
,7507,7517,7523,7529,7537,7541,7547,7549,7559,7561 
,7573,7577,7583,7589,7591,7603,7607,7621,7639,7643 
,7649,7669,7673,7681,7687,7691,7699,7703,7717,7723 
,7727,7741,7753,7757,7759,7789,7793,7817,7823,7829 
,7841,7853,7867,7873,7877,7879,7883,7901,7907,7919};

void more(bigint n,int k)
{
	ll sum = 0;
	vector<ll> ans;
	bigint one(1);

	for (ll d = 0; d< k;d++)
	{
	  bigint new_d(primes[d]);
	  bigint zero(0);
	  bool can = false;
	  // cout<<n<<" "<<d<<endl;
      while (n % new_d == zero) {
      	sum++;
      	ans.push_back(primes[d]);
        n /= new_d;
        if(sum > 100)
        {
        	can=true;break;
        }	
      }
        if(can)
      	break;
    }
	bool have = false;
	if(n > one)
	{
		sum+=1;
		have = true;

	}
	cout<<sum<<endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
	if(have)
	{
		cout<<n<<endl;
	}
}

void primeFactors(ll n)
{
    // Print the number of 2s that divide n
    std::vector<ll> v;
    int sum = 0;
    while (n%2 == 0)
    {
    	sum++;
        v.push_back(2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
        	sum++;
           v.push_back(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
    {
    	v.push_back(n);
    	sum++;
    }
    cout<<sum<<endl;
    for (int i = 0; i < v.size(); ++i)
    {
    	cout<<v[i]<<endl;
    }
}
 
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string input;
		cin>>input;
		if(input.length() <= 9)
		{
			ll n = atol(input.c_str());
			primeFactors(n);
		}
		else if(input.length() <= 18)
		{
			bigint n(input);
			more(n,1000);
		}
		else
		{
			bigint n(input);
			more(n,35);
			// cout<<1<<endl;
			// cout<<input<<endl;
		}
	}
	return 0;
}
//23281403731 2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222