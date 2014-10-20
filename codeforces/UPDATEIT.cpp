#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n,u,q;
int tree[10005];
void update(int a,int val)
{
	while(a <= n)
	{
		tree[a] += val;
		a += (a & -a);
	}
}
void update_range(int a,int b,int val)
{
	update(a+1,val);
	update(b+2,-val);
}
int query(int a)
{
	int ans = 0;
	while(a > 0)
	{
		ans+= tree[a];
		a -= (a & -a);
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		cin>>n>>u;
		for (int i = 0; i < u; ++i)
		{
			int a,b,val;
			cin>>a>>b>>val;
			update_range(a,b,val);
		}
		cin>>q;
		for (int i = 0; i < q; ++i)
		{
			int c;
			cin>>c;
			cout<<query(c+1)<<endl;
		}
	}
}