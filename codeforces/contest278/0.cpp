#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool cont(ll a)
{
	a = abs(a);
	while(a > 0)
	{
		if(a%10 == 8)
		{
			return true;
		}
		a /= 10;
	}
	return false;
}
int main()
{
	ll a;
	cin>>a;
	a++;
	int ans = 1;
	while(!cont(a))
	{
		a++;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}