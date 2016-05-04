#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		ll N,M;
		cin>>N>>M;
		if(N == 1 || M == 1)
		{
			cout<<"No"<<endl;
			continue;
		}
		if(N%2 == 0 || M%2 == 0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}