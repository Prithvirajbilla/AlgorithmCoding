#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll dp[2005][2005] = {{0}};



int main()
{
	int n,k;
	cin>>n>>k;
	dp[1][0] = 1;
	for (int i = 0; i < k; ++i)
	{
		for (int j =1; j <= n; ++j)
		{
			for(int k = j; k<=n;k+=j)
			{
				dp[k][i+1]+=dp[j][i];
				dp[k][i+1]%= mod;
			}
		}
	}
	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 1; j <= k ; ++j)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	ll ans = 0;
	for(int i=1; i<= n; i++)
	{
		ans+=dp[i][k];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;

}