#include <bits/stdc++.h>
using namespace std;
//1,5,10,25,50
int dp[30005];
int main()
{
	while(!cin.eof())
	{
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i=1; i<= n;i++)
		{
			dp[i] = (i-1 >= 0?dp[i-1]:1)*(i-5 >= 0?dp[i-5]:1)*(i-10 >= 0?dp[i-10]:1);
			dp[i] *= (i-25 >= 0? dp[i-25]:1) * (i-50 >= 0?dp[i-50]:1);
			cout<<dp[i]<<" ";
		}
		cout<<endl;
		cout<<dp[n]<<endl;
	}
}