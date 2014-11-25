#include <bits/stdc++.h>
using namespace std;
int a[100005] = {0};

int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	long long int ans = 0;
	for(int i=n-1;i >= 0; i--)
	{
		ans = ans + (a[i]+1);
		ans = ans/2;
	}
	cout<<ans<<endl;
	return 0;
}