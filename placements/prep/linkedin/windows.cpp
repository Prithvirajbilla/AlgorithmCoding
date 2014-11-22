#include <bits/stdc++.h>
using namespace std;
int a[10000] = {0};
multiset<int> b;

int main()
{
	int n,m;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		b.insert(a[i]);
	}
	cin>>m;
	int res = 0;
	for (int i = 0; i < m; ++i)
	{
		int k = *b.rbegin();
		// cout<<k<<endl;
		b.erase(--b.end());
		res+=k;
		b.insert(--k);
	}
	cout<<res<<endl;
}