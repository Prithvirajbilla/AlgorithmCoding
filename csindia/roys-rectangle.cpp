#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ll x,y,x1,y1,x2,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		vector<ll> res;
		res.pb(abs(x-x1));
		res.pb(abs(x-x2));
		res.pb(abs(y-y1));
		res.pb(abs(y-y2));
		cout<<*min_element(res.begin(),res.end())<<endl;
	}
	return 0;
}