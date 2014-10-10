#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ll x,y;
		cin>>x>>y;
		while(!(x == 1 || y == 1))
		{
			x =(x+1)/2; y =(y+1)/2;
		}
		if(x > y)
		{
			swap(x,y);
		}
		// x < y
		int count = 0;
		while(y != 1)
		{
			 y =(y+1)/2;
			 count++;
		}
		
	}
}