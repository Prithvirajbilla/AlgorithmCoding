#include <bits/stdc++.h>
using namespace std;
int array[100000];int n;
int tree[100000];
void increment(int a,int b)
{
	tree[a+1]+=b;
	int k = a+1;
	while(k < n+1)
	{
		k += (k &-k);
		tree[k] +=b;
	}
}
void query(int b)
{
	int k = b+1;
	int ret = 0;
	while(k > 0)
	{
		ret += tree[k];
		k -= (k & -k);
	}
	cout<<ret<<endl;
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
	for (int i = 1; i <= n; ++i)
	{
		tree[i] += array[i];
		int k = i;
		while(k < n+1)
		{
			k += (k & -k);
			tree[k] += array[i];
		}
	}
	int m;
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
		char c;
		int a,b;
		cin>>c>>a>>b;
		if(c == 'a')
		{
			increment(a,b); //increment a by b;
		}
		else if(c == 'g')
		{
			query(b); //get the sum from 1 to b;
		}
	}
	return 0;
}