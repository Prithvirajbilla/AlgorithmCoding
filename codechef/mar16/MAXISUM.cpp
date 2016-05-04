#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T,N,K;
ll A[100005],B[100005];
ll ans;
int main(){
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		ans = 0;
		memset(A,0,sizeof A);
		memset(B,0,sizeof B);
		cin>>N>>K;
		for (int j = 0; j < N; ++j)
		{
			cin>>A[j];
		}
		ll tp = 0;
		for (int j = 0; j < N; ++j)
		{
			cin>>B[j];
			if(abs(B[j]) > tp)
				tp = abs(B[j]);
		}
		for (int j = 0; j < N; ++j)
		{
			ans+= A[j]*B[j];
		}
		ans+= tp*K;
		cout<<ans<<endl;
	}
	return 0;
}