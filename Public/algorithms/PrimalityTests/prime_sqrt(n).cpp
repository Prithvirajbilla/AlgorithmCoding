#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPrime(ll n)
{
	if( n < 2)
	{
		return false;
	}
	else if(n <= 3)
	{
		return true;
	}
	else
	{
		for (int i = 2; i < sqrt(n)+2; ++i)
		{
			if(n%i == 0)
			{
				return false;
			}
		}
		return true;
	}
}
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	cout<<isPrime(n)<<endl;
	return 0;
}