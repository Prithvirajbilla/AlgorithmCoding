#include <bits/stdc++.h>
using namespace std;
int n,m,d;
int h[505];
int dp[20005];
void fill(int k)
{
	memset(dp,0,sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= k; ++i)
	{
		if(i-d >= 0)
		{
			dp[i] = (dp[i-d]+1)%2;
		}
		else
			dp[i] = 0;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(h,0,sizeof(h));
		cin>>n>>m>>d;
		for (int i = 0; i < n; ++i)
		{
			cin>>h[i];
		}
		fill(*max_element(h,h+n));
		int yes = 0;
		for (int i = 0; i < n; ++i)
		{
			yes ^= dp[h[i]];
		}
		cout<<yes<<endl;
		if( yes == 0 && m%2 == 0)
		{
			cout<<"NO"<<endl;
		}
		else if(yes == 0 && m%2 == 1)
		{
			cout<<"YES"<<endl;
		}
		else if(m%2 == 1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}

}