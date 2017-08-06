#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int X[200005];
int Y[200005];

int main(int argc, char const *argv[])
{	
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		memset(X, 0 ,sizeof(X));
		memset(Y, 0, sizeof(Y));
		for(int i=0 ;i < N; i++) {
			cin>>X[i];
		}
		for(int i=0 ;i < N; i++) {
			cin>>Y[i];
		}
		ll ans[2];
		for(int i=0; i< 2;i ++){
			ans[i] = 0;
			for(int j=0; j< N; j++){
				ans[i]+=((j+i)%2 ==0 ?X[j]:0) + ((j+i+1)%2 == 0 ?Y[j]:0);
			}
		}
		cout<<min(ans[0],ans[1])<<endl;
	}
	return 0;
}