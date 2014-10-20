#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
ll dp[101][101];
ll extra[101][101][101];
int main()
{
	int t;
	cin>>t;
	int cas = 1;
	for (cas = 1; cas <= t; cas++)
	{
		int m,n;
		cin>>m>>n;
		ll ans = 0;
		memset(dp,0,sizeof(dp[0][0])*101*101);
		memset(extra,0,sizeof(extra[0][0][0])*101*101*101);
		for (int i = 1; i <= n; ++i)
		{
			dp[1][i] = 1;
			for(int k = 1; k <= i-1+1; k++)
				extra[1][i][k] = i;
		}
		for (int i = 2; i <= m; ++i)
		{
			for (int j = i; j <= n ; ++j)
			{
				for (int k = 1; k <= j-i+1 ; ++k)
				{
					dp[i][j] += ((extra[i-1][j-k][k]+1)*dp[i-1][j-k])%mod;
					extra[i][j][k] = extra[i-1][j-k][k]+k;
				}
			}
		}
		cout<<dp[m][n]<<endl;
	}
}