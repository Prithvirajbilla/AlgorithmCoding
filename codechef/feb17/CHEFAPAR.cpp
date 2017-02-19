#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll A[100005],B[100005];
int main()
{
	int T;
	cin>>T;
	for(int i=0; i< T; i++)
	{
		memset(A, 0, sizeof(A));
		memset(B,0, sizeof(B));
		ll N;
		cin>>N;
		ll k = 0;
		for(ll j =0 ;j < N; j++) {
			cin>>A[j];
			if(A[j] == 1) {B[k] = j;k++;}
		}
		ll ans = 0;
		for(ll j = 0; j < k; j++){
			if(B[j] != j) ans+=100;
		}
		ans+=(N-k)*1100l;
		cout<<ans<<endl;
	}
	return 0;
}