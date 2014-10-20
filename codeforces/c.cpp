#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll choose[1005][1005];
list<int>  buses[1005];
list<int> second_time[1005];
int main()
{
	int n,d;
	ll k;
	cin>>n>>k>>d;
	if(k > n)
	{
		k = n;
	}
	int ratio = n/k;
	for (int i = 1; i < k; ++i)
	{
		for (int j = 1; j <= ratio; ++j)
		{
			buses[i].push_back((i-1)*ratio+j);
			choose[1][(i-1)*ratio+j] = i;
/*			cout<<i<<" "<<(i-1)*ratio+j<<endl;
*/		}
	}
	for(int i = (k-1)*ratio+1; i <= n;i++)
	{
		buses[k].push_back(i);
/*		cout<<k<<" "<<i<<endl;
*/		choose[1][i] = k;
	}
/*	for (int i = 1; i <= n ; ++i)
	{
		cout<<choose[1][i]<<" ";
	}
	cout<<endl;
*/
	for(int i = 1; i< d;i++)
	{
		
	}
}