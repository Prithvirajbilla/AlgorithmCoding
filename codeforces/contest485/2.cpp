#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[63] = {0};
ll solve(ll a, ll b)
{
	if(a == b)
		return a;
	ll val;
	for (int i = 0; i <= 62; ++i)
	{
		if(b+1 < dp[i])
		{
			val = dp[i-1];
			break;
		}
		else if(b== dp[i])
		{
			val = dp[i];
			break;
		}
	}
	if(val == 1)
		return 1;
	if(val-1 >= a)
		return val-1;
	else
	{
		ll a1 = a - val;
		ll b1 = b- val;
		return val+solve(a1,b1);
	}

}
int main()
{
	dp[0] = 1;
	for (int i = 1; i <= 62; ++i)
	{
		dp[i] = dp[i-1]*2;
	}
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		ll a,b;
		cin>>a>>b;
		cout<<solve(a,b)<<endl;
	}
}