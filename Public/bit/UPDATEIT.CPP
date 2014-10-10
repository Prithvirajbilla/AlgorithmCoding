#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n,u,q;
int array[10005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,u;
		scanf("%d%d",&n,&u);
		memset(array,0,sizeof(array));
		for (int i = 0; i < u; ++i)
		{
			int a,b,val;
			scanf("%d%d%d",&a,&b,&val);
			array[a] += val;
			array[b+1] += -val;
		}
		for (int i = 1; i < n; ++i)
		{
			array[i]= array[i]+array[i-1];
		}
		cin>>q;
		for (int i = 0; i < q; ++i)
		{
			int c;scanf("%d",&c);
			 printf("%d\n",array[c]);
		}
	}
}