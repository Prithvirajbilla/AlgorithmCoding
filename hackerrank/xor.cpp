#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll array[100005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(array,0,sizeof(array));
		int n;
		cin>>n;
		for (int i = 1; i <= n; ++i)
		{
			cin>>array[i];
		}
		//1 -- n || n -- n;
		// 1 2 3 4
		//1 2 3 4 1 2 2 3 3 4 1 2 3 2 3 4 1 2 3 4
		//1 2 3 4 5 1 2 2 3 3 4 4 5 1 2 3 2 3 4 3 4 5 1 2 3 4 2 3 4 3 4 5 1 2 3 4 5
		vector<ll> req;
		for (int i = 1; i <= n ; ++i)
		{
			if(n-2*(i-1) > 0)
			{
				
			}
		}
	}
	return 0;
}