#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll modulo(ll a,ll b, ll c)
{
	if( b==  0)
		return 1;
	else if(b%2 == 1)
	{
		ll temp = modulo(a,b/2,c);
		temp*=temp;
		temp%=c;
		return (a*temp)%c;
	}
	else
	{
		ll temp = modulo(a,b/2,c);
		temp*=temp;
		temp%=c;
		return temp;
	}
}
bool miller(ll n,int no_of_iterations)
{
	if(n < 2)
	{
		return false;
	}
	else if(n != 2 && n%2 == 0)
	{
		return false;
	}
	ll a = n-1;
	ll r = 0;
	while(a%2 == 0)
	{
		a=a/2;
		r++;
	}
	ll d = a;
	for (int i = 0; i < no_of_iterations; ++i)
	{
		ll ran = rand()%(n-1)+1;ll temp =d;
		ll mod = modulo(ran,temp,n);
		
	}
}
int main(int argc, char const *argv[])
{
	ll n;
	cout<<miller(n,20)<<endl;
	return 0;
}