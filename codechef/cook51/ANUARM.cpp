#include <bits/stdc++.h>
using namespace std;
int n,m;
int array[100005];
int query[100005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for (int i = 0; i < m; ++i)
		{
			cin>>query[i];
		}
		sort(query,query+m);
		int m1 = query[0];
		int m2 = query[m-1];
		for (int i = 0; i < n; ++i)
		{
			cout<<max(abs(i-m1),abs(i-m2))<<" ";
		}
		cout<<endl;
	}
}