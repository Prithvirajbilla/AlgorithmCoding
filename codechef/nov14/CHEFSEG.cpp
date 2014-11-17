#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll pow2[64]= {0};

int main()
{
	pow2[0] = 0;
	for (ll i = 1; i <= 63; ++i)
	{
		ll as = 1;
		as = as << (i-1);
		pow2[i] = pow2[i-1] + as;
	}
	int t;
	cin>>t;
	while(t--)
	{
		ll x, k;
		cin>>x>>k;
		int i;
		for (i = 0; i <= 63; ++i)
		{
			if(pow2[i] >= k)
			{
				break;
			}
		}
		ll extra = k - pow2[i-1];
		double ans = x;
		ll den = (ll)1<<i;
		ans = ans/den;
		ans *= (2*extra-1);
		printf("%.8f\n",ans);
	}
	return 0;
}
//1000000000