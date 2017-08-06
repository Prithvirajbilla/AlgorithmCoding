#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;

int main() {
	cin>>n>>m;
	int a[n][m];
	for(int i=0; i< n; i++){
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
		}
	}
	// cout<<n<<" "<<m<<endl;
	ll ans = 0;

	for(int i =0; i<n; i++) {
		for(int j=0; j< m;j++) {
			for(int i1=i; i1<n;i1++) {
				for(int j1=j;j1<m;j1++){
					ll previous = -1;
					ll totalIncreasing = true;
					// cout<<i<<" "<<j<<" "<<i1<<" "<<j1<<endl;
					for(int i2=i;i2<=i1;i2++){
						ll increasing = true;
						for(int j2=j; j2<=j1;j2++) {
							if(previous <= a[i2][j2]) {

							}
							else{
								increasing &= false;
								break;
							}
							previous = a[i2][j2];
						}
						if(increasing == false) {
							totalIncreasing &= false;
							break;
						}
					}-0
					if(totalIncreasing) {
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}