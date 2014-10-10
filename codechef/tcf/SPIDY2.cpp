#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll A[200005] = {0};
bool power2(ll v)
{
	return v && !(v & (v - 1));
}
ll ans[200005] = {0};
int p2[20] = {0};
int main()
{
	int N;
	cin>>N;
	for (int i = 0; i < 20; ++i)
	{
		p2[i] = 1<<i;
	}
	for (int i = 0; i < N; ++i)
	{
		cin>>A[i];
	}
	for (int i = 0; i < N; ++i)
	{
		ans[i] = 10000000000;
	}
	ans[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		int now = i;
		for(int j = 0;j < 20; j++)
		{
			if(i < p2[j])
			{
				break;
			}
			else
			{
				ans[i] = min(ans[i-p2[j]]+abs(A[i]-A[i-p2[j]]),ans[i]);
			}
			// cout<<ans[i]<<" ";
		}
		// cout<<endl;
	}
	// for (int i = 0; i < N; ++i)
	// {
	// 	cout<<ans[i]<<" ";
	// }
	// cout<<endl;
	cout<<ans[N-1]<<endl;
	return 0;
}