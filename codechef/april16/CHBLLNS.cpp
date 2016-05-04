#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		ll C[3],K;
		for (int j = 0; j < 3; ++j)
		{
			cin>>C[j];
		}
		cin>>K;
		ll ans = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (C[j] < K){
				ans += C[j];
			}
			else{
				ans += K-1;
			}
		}
		ans+=1;
		cout<<ans<<endl;
	}
	return 0;

}