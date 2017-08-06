#include <bits/stdc++.h>
using namespace std;
int A[1000005];
int B[1000005];
int main() {
	int T;
	cin>>T;
	while(T--){
		int o1, o2;
		cin>>o1>>o2;
		memset(A, 0 , sizeof(A));
		memset(B,0, sizeof(B));

		for(int i=0; i < o1*o2; i++){
			cin>>A[i];
		}
		int ans = 0;
		for(int i=0;i< o1;i++){
			for(int j=0;j<o2;j++){
				B[i]+=A[o2*i+j];
			}
			if(B[i] > o2/2) ans++;
		}
		if(ans > o1/2) cout<<1<<endl;
		else {
			for(int i = 1; i < o2; i++)  {
				ans = 0;
				// cout<<"i="<<i<<endl;
				for(int j = 0; j < o1; j++) {
					int f1_idx = (o2*(j+1)+i-1)%(o2*o1);
					int f2_idx = (o2*j+i-1)%(o2*o1);
					// cout<<f1_idx<<endl;
					B[j] = B[j] + A[f1_idx] - A[f2_idx];
					// cout<<B[j]<<endl;
					if(B[j] > o2/2) ans++;
				}
				if(ans > o1/2){
					break;
				}
			}
			if(ans > o1/2) cout<<1<<endl;
			else cout<<0<<endl;
		}

	}
	return 0;
}