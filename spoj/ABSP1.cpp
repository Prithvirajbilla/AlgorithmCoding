#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, n;
ll A[10005];

int main(int argc, char const *argv[])
{
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		memset(A, 0, sizeof A);
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
		}

		ll ans = 0;
		ll prev = 0;
		for(int i = 1; i < n; i++) {
				ll now_prev = prev + i*(A[i]-A[i-1]);
				ans+= now_prev;
				prev = now_prev;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}