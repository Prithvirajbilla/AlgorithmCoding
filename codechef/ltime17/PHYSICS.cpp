#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll h[10005] = {0};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; ll f;
		cin>>n>>f;
		memset(h,0,sizeof(h));
		for (int i = 0; i < n; ++i)
		{
			cin>>h[i];
		}
		sort(h,h+n);
		double max_power = h[n-1];
				max_power/=h[0];
				max_power = log(max_power)/log(f);
		vector<ll> pows;
		ll s = 1;
		for (int i = 0; i < (int)ceil(max_power)+2; ++i)
		{
			pows.push_back(s);
			s *= f;
		}

		ll ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < pows.size(); ++j)
			{
				ll kk = pows[j]*h[i];
				int pos = lower_bound(h+i+1,h+n,kk) -h;
				int pos2 = upper_bound(h+i+1,h+n,kk)-h;
				if(h[pos] == kk)
					ans+=pos2-pos;
			}
		}
		cout<<ans<<endl;
	}
}