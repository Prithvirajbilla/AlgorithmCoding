#include <bits/stdc++.h>
using namespace std;
int dp[55][55] = {0};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(dp,0,sizeof(dp[0][0])*55*55);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>dp[i][j];
			}
		}
		for(int i = 0; i< n; i++)
		{
			for (int j = m-1; j > 0 ; j--)
			{
				if(dp[i][j] >= dp[i][j-1])
				{
					dp[i][j-1]--;
				}
			}
		}
		// for (int i = 0; i < n; ++i)
		// {
		// 	for (int j = 0; j < m; ++j)
		// 	{
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		int nim = 0;
		for(int i=0; i<n; i++)
		{
			nim^= dp[i][0];
		}
		if(nim == 0)
		{
			cout<<"SECOND"<<endl;
		}
		else
		{
			cout<<"FIRST"<<endl;
		}
	}
}