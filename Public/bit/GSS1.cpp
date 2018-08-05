#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int  max_n = 500005;
ll tree[max_n*4];
int array[500005];
int n;
void init(int node,int left,int right)
{
	if(left > right)
		return ;
	if(left == right)
	{
		tree[node] = array[left];
	}
	else
	{
		init(2*node,left,(left+ right)/2);
		init(2*node+1,(left+right)/2+1,right);
		tree[node] = max(tree[2*node] + tree[2*node+1],max(tree[2*node],tree[2*node+1]));
	}
}
ll query(int node,int nr_r,int nr_l,int a,int b)
{
	if(nr_r == a && nr_l == b)
		return tree[node];
	else if(nr_r >b || nr_l < a || nr_r > nr_l)
		return 0;
	else
	{
		ll q1 = query(2*node,nr_r,(nr_r+nr_l)/2,a,b);
		ll q2 = query(2*node+1,(nr_r+nr_l)/2+1,nr_l,a,b);
		return max(q1+q2,max(q1,q2));
	}
}
int main()
{
	cin>>n;
	memset(array,0,sizeof(array));
	memset(tree,0,sizeof(tree));
	for (int i = 1; i <= n; ++i)
	{
		cin>>array[i];
	}
	init(1,1,n);
	int m;
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin>>a>>b;
		cout<<query(1,1,n,a,b)<<endl;
	}
	return 0;
}