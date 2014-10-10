#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int nk;
int n;
pair<int,int> con[100000];
ll bit[100000];
void update(int x)
{
	while(x <= nk)
	{
		bit[x]++;
		x += x & -x;
	}
}
ll query(int x)
{
	ll ans = 0;
	while(x > 0)
	{
		ans+=bit[x];
		x -= x & -x;
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	int cs;
	for(cs = 1;cs <= t; cs++)
	{
		cin>>n;
		memset(bit,0,sizeof(bit));
		memset(con,0,sizeof(con));
		nk = 0;
		for (int i = 0; i < n; ++i)
		{
			int a,b;
			cin>>a>>b;
			con[i] = make_pair(a,b);
			nk = max(nk,b);
		}
		sort(con,con+n);
		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			update(con[i].second);
			ans+= i+1 - query(con[i].second);
		}
		cout<<"Case #"<<cs<<": "<<ans<<endl;
	}	
}