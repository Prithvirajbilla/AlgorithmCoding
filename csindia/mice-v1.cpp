#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int* a = new int[n];
		int* b = new int[n];
		for(int i =0; i<n;i++)
			cin>>a[i];
		for (int i = 0; i < n; ++i)
		{
			cin>>b[i];
		}
		sort(a,a+n);sort(b,b+n);
		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans+=abs(a[i]-b[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}