#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int binary_search(vector<pair<int,pair<int,int> > > occ, int k) {
	int a = 0,b = occ.size()-1;
	while (a <= b){
		int m = (a+b)/2;
		if(k <= occ[m].first)
		{
			b = m-1;
		}
		else {
			a = m+1;
		}
	}
	return a - 1 < 0 ? -1 : a - 1;
}

int A[100005];
int main() {
	memset(A,0,sizeof(A));
	int N,M;
	cin>>N>>M;
	for(int i=0; i< N; i++) cin>>A[i];
	
	vector<pair<int,pair<int,int> > > occ;
	occ.push_back(make_pair(0,pii(A[0],1)));

	for(int i = 1; i< N; i++) {
		if(occ.back().second.first == A[i]) occ.back().second.second +=1;
		else occ.push_back(make_pair(i,pii(A[i],1)));
	}

	while(M--){
		int L,R,k;
		cin>>L>>R>>k;
		L--;R--;
		bool check = true;
		int p = binary_search(occ,L);
		if(p > 0) p--;

		for(int i=p; i< occ.size(); i++) {
			int a = occ[i].first;
			int b = occ[i].first+occ[i].second.second-1;
			// cout<<occ[i].first<<" "<<occ[i].second.first<<" "<<occ[i].second.second<<endl;
			// cout<<L<<" "<<R<<" "<<a<<" "<<b<<endl;
			if(L > b) continue;
			if(R < a) break;

			int o = 0;
			if(a <= L) {
				if(R <= b) {
					o = R-L+1;
				}
				else {
					o = b-L+1;
				}
			}
			else if(L < a) {
				if(R <= b) o = R-a+1;
				else o = b-a+1;
			}
			// cout<<o<<endl;
			if(o >= k) {
				cout<<occ[i].second.first<<endl;
				check= false;
				break;
			}

		}
		if(check) {
			cout<<-1<<endl;
		}

	}
	return 0;
}