#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		ll current = 1;
		for (int i = 0; i < s.length(); ++i)
		{
			int level = i+1;
			if(level%2 == 1)
			{
				if(s[i] == 'l')
				{
					current = 2*current;
				} 
				else
				{
					current = 2*current + 2;
				}
			}
			else
			{
				if(s[i] == 'l')
				{
					current = 2*current - 1;
				}
				else
				{
					current = 2*current + 1;
				}
			}
			if(current > mod)
				current = current%mod;
		}
		cout<<current<<endl;
	}
}