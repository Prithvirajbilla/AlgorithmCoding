#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int t;
pair<int,int> array[1000000];
ll ans = 0;
ll tree[1000000];
int k;
int n,m;
ll read(int x)
{
	ll sum = 0;
	while(x > 0)
	{
		sum+=tree[x];
		x -= x& -x;
	}
	return sum;
}
void update(int x,int y)
{
	while(x <= m)
	{
		tree[x] +=y;
		x+= x&-x;
	}
}
int main()
{	
	cin>>t;
	for (int i = 1; i <= t; ++i)
	{
		scanf("%d %d %d",&n,&m,&k);
		ans = 0;
		memset(array,0,sizeof(array));
		memset(tree,0,sizeof(tree));
		for (int j = 0; j < k; ++j)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			array[j] = make_pair(a,b);
		}
		sort(array,array+k);
		// quickSort(array,0,k-1);
		for (int j = 0; j < k; ++j)
		{
			update(array[j].second,1);
			ans+=(j+1-read(array[j].second));
		}
		printf("Test case %d: %lld\n",i,ans);
	}

}