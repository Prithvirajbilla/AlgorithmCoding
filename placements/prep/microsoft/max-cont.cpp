#include <bits/stdc++.h>
using namespace std;
int a[100000] = {0};
int prefix[100000] = {0};
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for (int i = 1; i < n; ++i)
	{
		prefix[i] = prefix[i-1]+a[i];
	}
	map<int,int> m;
	int start = 0;
	int end;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if(m.find(a[i])==m.end())
		{
			m[a[i]]=i;
			end = i;
			ans = max(ans,prefix[end]-prefix[start]+a[start]);
		}
		else

		{	
			int ind = m[a[i]];
			for (int k = start; k <= ind; ++k)
			{
				m.erase(a[k]);
			}
			m[a[i]] = i;
			start = ind+1;
			end = i;
			ans = max(ans,prefix[end]-prefix[start]+a[start]);
		}

	}
	cout<<ans<<endl;
}