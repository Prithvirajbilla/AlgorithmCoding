#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll x[1005],y[1005];
int main()
{
	int n;
	cin>>n;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i]>>y[i];
	}
	ll wt = *max_element(x,x+n) - *min_element(x,x+n);
	ll ht = *max_element(y,y+n) - *min_element(y,y+n);
	ll ans = max(abs(wt),abs(ht));
	ans *= ans;
	cout<<ans<<endl;
}