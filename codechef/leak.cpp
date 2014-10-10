#include <bits/stdc++.h>
using namespace std;
#define ll signed long long int

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ll x,y;
		cin>>x>>y;
		if(x > 0)
		{
			if(x%2 == 1)
			{
				ll l = -1*(x-1);
				ll r = 2*x+l;
				if(y >= l && y <= r)
				{
					cout<<"YES"<<endl;
					continue;
				}
			}
		}
		else
		{
			if(x%2 == 0)
			{
				ll l = x;
				ll r = -1*x;
				if(y>=l && y<= r)
				{
					cout<<"YES"<<endl;
					continue;
				}
			}
		}
		if(y >= 0)
		{
			if(y%2 == 0)
			{
				ll l = -1*y;
				ll r = 2*y-1 + l;
				if(x>=l && x<= r)
				{
					cout<<"YES"<<endl;
					continue;
				}
			}
		}
		else
		{
			if(y%2 == 0)
			{
				ll l = y;
				ll r = (-1*y)+1;
				if(x>= l && x<= r)
				{
					cout<<"YES"<<endl;
					continue;
				}
			}
		}
		cout<<"NO"<<endl;
	}
}