#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll m,n;
	cin>>n>>m;
	ll k1 = n*n + (m-1)*(m-1);
	k1 = k1 - (2*n -1)*(m-1) - n;
	k1 = k1/2;
	ll k2 = 0;
	if(n%m == 0)
	{
		ll a = n/m;
		k2 = a*a*m;
	}
	else
	{
		ll a = n/m;
		k2 = (m - n%m)*a*a + (n%m)*((n - a*(m- n%m))/(n%m))*((n - a*(m- n%m))/(n%m));
	}
	k2 -= n;
	k2/=2;
	vector<ll> as;
	as.push_back(k1);
	as.push_back(k2);
	sort(as.begin(),as.end());
	cout<<as[0]<<" "<<as[1]<<endl;
	return 0;
}