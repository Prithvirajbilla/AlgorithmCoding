#include <bits/stdc++.h>
using namespace std;
int t,n,c;
#define ll long long int
ll bit1[1000005],bit2[1000005];
void update(ll a,ll val,ll * k)
{
	while(a <= n)
	{
		k[a]+=val;
		a+= (a & -a);
	}
}
void update_n(ll a,ll b,ll val)
{
	update(a,val,bit1);
	update(b+1,-val,bit1);
	update(a,val*(a-1),bit2);
	update(b+1,-val*(b),bit2);
}
ll query_in(ll a,ll* k)
{
	ll ans=0;
	while(a > 0)
	{
		ans+=k[a];
		a-= (a& -a);
	}
	return ans;
}
ll query_1_a(ll a)
{
	return a*(query_in(a,bit1)) - query_in(a,bit2);
}
ll query(ll a,ll b)
{
	return query_1_a(b) - query_1_a(a-1);
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		memset(bit1,0,sizeof(bit1));
		memset(bit2,0,sizeof(bit2));
		for (int i = 0; i < c; ++i)
		{
			int f;
			cin>>f;
			if(f == 0)
			{
				ll p,q,v;
				cin>>p>>q>>v;
				update_n(p,q,v);
			}
			else
			{
				ll p,q;
				cin>>p>>q;
				cout<<query(p,q)<<endl;
			}
		}
	}
	return 0;
}