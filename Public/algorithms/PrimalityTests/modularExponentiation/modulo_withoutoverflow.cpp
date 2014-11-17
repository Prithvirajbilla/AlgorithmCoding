#include <bits/stdc++.h>
using namespace std;

#define ll long long int
// find (a*b)%c
ll modulo(ll a,ll b, ll c)
{
	ll x = 0; ll y = a%c;
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x+y)%c;
		}
		y = (y*2)%c;
		b/=2;
	}
	return x%c;
}
int main(int argc, char const *argv[])
{
	ll a,b,c;
	cin>>a>>b>>c;
	cout<<modulo(a,b,c)<<endl;
	return 0;
}