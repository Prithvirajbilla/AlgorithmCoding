#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;

int main() {
	cin>>n>>m;
	int a[n][m];
	int right[n][m];
	int down[n][m];
	int diag[n][m];
	int dp[n][m];

	memset(a, 0, sizeof(a[0][0]) * m * n);
	memset(right, 0, sizeof(right[0][0]) * m * n);
	memset(down, 0, sizeof(down[0][0]) * m * n);
	memset(diag, 0, sizeof(diag[0][0])* m * n);
	memset(dp, 0, sizeof(dp[0][0])* m * n);

	for(int i=0; i< n; i++){
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
		}
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (j==0)
			{
				right[i][j] = 1;
			}
			else
			{
				if (a[i][j] >= a[i][j-1])
				{
					right[i][j] = 1 + right[i][j-1];
				}
				else
				{
					right[i][j] = 1;
				}
			}

			if (i == 0)
			{
				down[i][j] = 1;
			}
			else
			{
				if (a[i][j] >= a[i-1][j])
				{
					down[i][j] = 1 + down[i-1][j];
				}
				else
				{
					down[i][j] = 1;
				}
			}

			if (i==0 || j==0)
			{
				diag[i][j] == 0;
			}
			else
			{
				if (diag[i-1][j-1] <= diag[i][j])
				{
					diag[i][j] = 1 + diag[i-1][j-1];
				}
				else
				{
					diag[i][j] == 0;
				}
			}
		}
	}

	for(int i =0; i< n; i++){
		for(int j= 0; j<m; j++){
			if( i == 0 && j == 0) {
				dp[i][j] = 1;
			}
			else if(i == 0) {
				dp[i][j] = right[i][j];
			}
			else if(j == 0) {
				dp[i][j] = down[i][j];
			}
			else {
				// cout<<dp[i][j]<<" "<<i <<" "<<j<<endl;
				if(diag[i][j] > 1) {
					if(diag[i][j] <= std::max(right[i][j-1],down[i-1][j] )) {
						dp[i][j] = (diag[i][j])*(std::max(right[i][j-1],down[i-1][j])+1)-1;
					}
					else if(diag[i][j] >= std::max(right[i][j-1],down[i-1][j] )) {
						dp[i][j] = (right[i][j-1]+1)*(down[i-1][j]+1)-1;
					}
					else if(diag[i][j] >= std::min(right[i][j-1],down[i-1][j]) && diag[i-1][j-1] <= std::max(right[i][j-1],down[i-1][j])) {
						dp[i][j] =  (diag[i][j])*(right[i][j-1]+1) +(diag[i][j])*(down[i-1][j]+1) - (diag[i][j])*(diag[i][j]);
						dp[i][j] -=1;
					}
				}
				else {
					dp[i][j] = (right[i][j] + down[i][j] - 1);
				}
				// cout<<dp[i][j]<<" "<<i <<" "<<j<<endl;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for(int j =0; j< m; j++) {
			ans += dp[i][j];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}