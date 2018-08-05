#include <bits/stdc++.h>
using namespace std;
int tree[100000];
int array[100000];
int n;
int read(int a)
{
	int ans = 0;
	int k = a+1;
	while(k >= 0)
	{
		ans += tree[k];
		k -= (k & -k);
	}
	return ans;
}
void update(int a,int b)
{
	tree[a+1]+=b;
	int k = a+1;
	while(k < n+1)
	{
		k += (k &-k);
		tree[k] +=b;
	}
}

int main()
{
	int n;
	cin>>n;
	memset(array,0,sizeof(array));
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		tree[i] += array[i-1];
		int k = i;
		while(k > n+1)
		{
			k += (k & -k);
			tree[k] += array[i-1];
		}
	}
}