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
		ll start = cbrt(6*n);
		int i = 1;
		while(true)
		{
			ll result = (start *(start+1)*(2*start+1))/6;
			if(result <= n)
				break;
			start--;
		}
		cout<<start<<endl;
	}
}