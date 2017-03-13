#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N;
int ch[305] = {0};
vector<vector<pair<ll,int> > > A;
int main(){
	cin>>N;
	for(int i=0 ; i< N; i++){
		vector<pair<ll,int> > row;
		for(int j=0; j<N;j++){
			ll k;
			cin>>k;
			row.push_back(pair<ll,int>(k,j));
		}
		sort(row.begin(),row.end());
		ll asc = 0; ll desc = 0;
		for(int j=0; j < N; j++) {
			asc+= (row[j].second - j)*(row[j].second - j);
			desc += (row[j].second - (N-j-1))*(row[j].second - (N-j-1));
		}
		if(asc < desc) ch[i] = 1;
		A.push_back(row);
	}
	for(int i=0; i< N; i++){
		if(ch[i] == 0) {
			for(int j=0; j< N; j++) {
				cout<<A[i][j].first<<" ";
			}
			cout<<endl;
		}
		else {
			for(int j=N-1; j>=0; j--) {
				cout<<A[i][j].first<<" ";
			}
			cout<<endl;
		}
	}

}