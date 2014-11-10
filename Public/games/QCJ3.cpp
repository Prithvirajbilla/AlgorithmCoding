#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin>>k;
			if(k%2 == 1)
				sum^=(i+1);
		}

		if(sum == 0)
		{
			cout<<"Hanks Wins"<<endl;
		}
		else
		{
			cout<<"Tom Wins"<<endl;
		}
	}
	return 0;
}