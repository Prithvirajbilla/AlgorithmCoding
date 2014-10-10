#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll in = 301388891;
ll ncr(int n,int r)
{

	ll num = 1,den = 1;
	ll ans = 1;
	for (int i = n,j = r; j > 0 ; j--,i--)
	{
		num*=i;
		num %=mod;
	}
	num*=in;
	num %= mod;
}
int main()
{
	int N;
	cin>>N;
	if(N%2 == 0)
		N /= 2;
	else
		N+=1,N/=2;

	if(N-1>= 6)
	{
		ll ans = ncr(N-1,6);
		cout<<ans<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}