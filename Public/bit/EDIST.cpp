#include <bits/stdc++.h>
using namespace std;
int d[2005][2005];
string a,b;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		memset(d,0,sizeof(d[0][0])*2005*2005);
		int m = a.length();
		int n = b.length();
		for (int i = 0; i <= m; ++i)
		{
			d[0][i] = i;
		}
		for (int i = 0; i <= n ; ++i)
		{
			d[i][0] = i;
		}
		for(int j =0; j< n; j++)
		{
			for (int i = 0; i < m; ++i)
			{
				int cost = (a[i] == b[j])?0:1;
				d[j+1][i+1] = min(d[j][i]+cost,min(d[j+1][i]+1,d[j][i+1]+1));
			}
		}
		cout<<d[n][m]<<endl;
	}
}