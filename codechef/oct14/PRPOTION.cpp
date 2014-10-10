#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll r[105],g[105],b[105];
#define max_3(a,b,c)  max(a,max(b,c))
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int R,G,B,M;
		cin>>R>>G>>B>>M;
		memset(r,0,sizeof(r));
		memset(g,0,sizeof(g));
		memset(b,0,sizeof(b));
		for (int i = 0; i < R; ++i)
		{
			cin>>r[i];
		}
		for (int i = 0; i < G; ++i)
		{
			cin>>g[i];
		}
		for (int i = 0; i < B; ++i)
		{
			cin>>b[i];
		}
		sort(r,r+R);
		sort(g,g+G);;
		sort(b,b+B);
		ll result = max_3(r[R-1],g[G-1],b[B-1]);
		ll now_array[3] = {r[R-1],g[G-1],b[B-1]};
		for (int i = 0; i < M; ++i)
		{
			int mi = max_element(now_array,now_array+3) - now_array;
			now_array[mi] /= 2;
			result = min(result,*max_element(now_array,now_array+3));

		}
		cout<<result<<endl;
	}
}