#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 20000000000
int T;
ll A[100005];
 
int main(){
	cin>>T;
	while(T--){
		ll N;
		cin>>N;
		memset(A, 0, sizeof(A));
		ll min[2] = {inf,inf};
		ll max[2] = {-1,-1};
		for(int i =0; i< N; i++){
			cin>>A[i];
			if(min[0] >= A[i]) {
				swap(min[0],min[1]);
				min[0] = A[i];
			}
			else if(min[1] >= A[i]) {
				min[1] = A[i];
			}
 
			if(max[0] <= A[i]) {
				swap(max[0],max[1]);
				max[0] = A[i];
			}
			else if(max[1] <= A[i]) {
				max[1] = A[i];
			}
		}
		if(min[1]-min[0] > 1 || min[1]-min[0] == 0) cout<<min[0]<<endl;
		else if(max[0]-max[1]> 1 || max[1]-max[0] == 0) cout<<max[0]<<endl;
		else {
			ll sum = 0;
			for(int i=0; i< N; i++){
				sum+= (A[i] - min[0]+1);
			}
			cout<<(sum - ((N*N - N)/2) + min[0] -1)<<endl;
		}
	}
	return 0;
} 
