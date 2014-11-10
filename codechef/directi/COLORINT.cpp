#include <bits/stdc++.h>
using namespace std;

int w[200]={0}; int c[200]={0};
vector<int> col_st[200];
bool dp[200][1000005] = {false};

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(w,0,sizeof(w));
		memset(c,0,sizeof(c));
		memset(col_st,0,sizeof(col_st));
		memset(dp,0,sizeof(dp[0][0])*200*1000005);

		int n,m,x;
		cin>>n>>m>>x;
		for (int i = 0; i < n; ++i)
		{
			cin>>w[i];
		}

		for (int i = 0; i < n; ++i)
		{
			cin>>c[i];
			col_st[c[i]].push_back(w[i]);
		}
		// dp[c][y] is true if you can make exactly y weight using 1..c colors 
		// for (int i = 1; i <= x; ++i)
		// {
			for (int j = 0; j < col_st[1].size() ; ++j)
			{
				dp[1][col_st[1][j]] = true;
			}
		// }
		
		for (int i = 0; i <= m; ++i)
		{
			dp[i][0] = true;
		}
		
		for (int i = 2; i <= m ; ++i)
		{
			for (int j = 1; j <= x ; ++j)
			{
				for (int k = 0; k < col_st[i].size(); ++k)
				{
					// if(j > col_st[i][k])
					// 	dp[i][j] |= dp[i-1][j-col_st[i][k]];
					if(dp[i-1][j])
						dp[i][j+col_st[i][k]] = true;
				}
			}
		}
		
		bool h = true;
		for (int i = x; i > 0 ; i--)
		{
			if(dp[m][i] == true)
			{
				h = false;
				cout<<x-i<<endl;
				break;
			}
		}
		
		if(h)
			cout<<-1<<endl;
	}
	return 0;
}