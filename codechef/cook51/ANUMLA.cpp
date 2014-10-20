#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		multiset<ll> dp;
		int n;
		cin>>n;
		int query = 1<<n;
		for (int i = 0; i < query; ++i)
		{
			ll k;
			cin>>k;
			dp.insert(k);
		}
		vector<int> remv;
		multiset<ll>::iterator it = dp.lower_bound(0);
		dp.erase(it);
		vector<int> ans;
		remv.push_back(0);
		int sz = 1;
		while(ans.size() < n)
		{
			int k = *dp.begin();
			// cout<<k<<endl;
			ans.push_back(k);
			if(ans.size() == n)
				break;
			for (int i = 0; i < sz; ++i)
			{
				remv.push_back(remv[i]+k);
			}
			for (int i = sz; i < remv.size(); ++i)
			{
				multiset<ll>::iterator it = dp.lower_bound(remv[i]);
				if(*it == remv[i])
					dp.erase(it);
			}
			sz = remv.size();
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}