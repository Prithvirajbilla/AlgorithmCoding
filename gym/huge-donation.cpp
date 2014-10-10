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
		int i = 1;
		while(n >= 0)
		{
			n-=i*i;
			i+=1;
		}
		cout<<i-1<<endl;
	}
}