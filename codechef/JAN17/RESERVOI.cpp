#include <bits/stdc++.h>
using namespace std;
#define ll long long
char A[1002][1002];
int N,M;
bool extreme(int i,int j) 
{
	return ((i == 1) && (j == 1) || (i == N) && (j == 1) || (i == N) && (j == M) || (i == 1) && (j == M));
}
bool side(int i, int j)
{
	return (j == M) || (i == N) || (j == 1);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(A, 0, sizeof(A[0][0])*1002*1002);
		cin>>N>>M;
		for(int i=1; i<= N; i++){
			for(int j=1; j<=M;j++){
				cin>>A[i][j];
			}
		}
		bool ans = true;
		for(int i = 1; i<=N; i++){
			for(int j=1; j <= M; j++){
				if(A[i][j] == 'B'){
					if(i < N && A[i+1][j] != 'B'){
						ans = false; break;
					}
				}
				else if(A[i][j] == 'W') {
					if(extreme(i,j)) {ans = false; break;}
					else if(side(i,j)) {ans = false; break;}
					else
					{
						if(!((A[i][j-1] == 'W' || A[i][j-1] == 'B') && 
							(A[i][j+1] == 'W' || A[i][j+1] == 'B') && 
							(A[i+1][j] == 'W' || A[i+1][j] == 'B') && 
							( i == 1 || (i > 1 && 
								(A[i-1][j] == 'W' || A[i-1][j] == 'A'))
							)
							))
							{ans = false; break;}

					}
					
				}
				else if(A[i][j] == 'A') {
					if(!((j == 1 || 
							(j > 1 && (A[i][j-1] == 'A' || A[i][j-1] == 'B'))
						  ) && 
						 (j == M || 
						 	(j < M && (A[i][j+1] == 'A' || A[i][j+1] == 'B'))
						  ) && 
						( i == 1 || (i > 1 && A[i-1][j] == 'A'))
						))
						{ans = false; break;}

				}

			}
			if(ans == false){
				break;
			}
		}
		if(ans) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		ans = true;
	}
}