#include <bits/stdc++.h>
using namespace std;
int a[10000]= {0};
int total_sum = 0;
int prefix[10000] = {0};
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		total_sum+=a[i];
	}
	prefix[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		prefix[i] = prefix[i-1]+a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if(total_sum-prefix[i] == prefix[i]-a[i])
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}