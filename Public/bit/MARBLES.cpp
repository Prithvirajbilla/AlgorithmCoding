#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll bin(ll n,ll k)
{
	k = min(n-k,k);
	ll ans = 1;ll den = 1;
	for (ll i = k,j= n; i > 0 ; i--,j--)
	{
		ans*= j;
		den*= i;
		ll g = __gcd(ans,den);
		ans /= g;
		den /= g;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<bin(n-1,k-1)<<endl;
	}
}