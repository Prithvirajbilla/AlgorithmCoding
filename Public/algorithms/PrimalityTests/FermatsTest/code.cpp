#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll modulo(ll a,ll b, ll c)
{
	if(b == 0)
		return 1;
	else if(b%2 == 1)
	{
		ll temp = modulo(a,b/2,c);
		temp = (temp*temp)%c;
		return (a*temp)%c;
	}
	else
	{
		ll temp = modulo(a,b/2,c);
		return (temp*temp)%c;
	}
}
bool fermat(ll n,int no_of_iterations)
{
	if(p == 1)
	{
		return false;
	}
	for (int i = 0; i < no_of_iterations; ++i)
	{
		ll a = rand()%(p-1)+1;
		if(modulo(a,p-1,p) != 1)
		{
			return false;
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	ll n;
	cout<<fermat(n,20)<<endl;
	return 0;
}