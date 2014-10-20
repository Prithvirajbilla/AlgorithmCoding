#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ans = n;
		ans *= (n+1);
		ans /= 2;
		cout<<ans+n<<endl;
	}
}