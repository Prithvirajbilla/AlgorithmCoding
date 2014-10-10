#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin>>N;
		int* array = new int[N];
		for (int j = 0; j < N; ++j)
		{
			cin>>array[j];
		}
		int* su = new int[N];
		fill(su,su+N,0)
		for (int j = 0; j < N; ++j)
		{
			su[array[j]]++;
		}
		for (int j = 1; j < N; ++j)
		{
			su[j]+=su[j-1];
		}
		long long int ans = 1;
		for (int j = 0; j < N; ++j)
		{
			ans = ans*(su[j]-j);
			if(ans == 0)
			{
				break;
			}
			ans%=mod;
		}
		cout<<ans<<endl;
	}
}