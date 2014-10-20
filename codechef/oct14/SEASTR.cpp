#include <bits/stdc++.h>
using namespace std;
string s,t;
int a,b,k;
int m,n;
// int v0[1000005],v1[1000005];
#define ll long long int
ll arr[2][100005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		cin>>a>>b>>k;
		// memset(arr, 0, sizeof(arr[0][0])*100005*2);
		m = s.length();
		n = t.length();
		if(m > n && (m-n)*a > k)
		{
			cout<<-1<<endl;
			continue;
		}
		else if(m < n && (n-m)*a > k)
		{
			cout<<-1<<endl;
			continue;
		}
		if(m>n)
		{
			swap(s,t);
			swap(m,n);
		}
		int ind = 0;
		for(int j=0; j< 2; j++)
		{
			for (int i = 0; i <= n; ++i)
			{
				arr[j][i] = 100000000;
			}
		}
		for (int j = 0; j <= n ; ++j)
		{
			arr[ind][j] = a*j;
		}
		for (int i = 0; i < m; ++i)
		{
			ind++;
			arr[ind%2][0] = a*(i+1);
			int start = max(0,i+1+n-m-k);
			int end = min(i+1+n-m+k,n-1);
			for (int j =start; j <= end ; ++j)
			{
				int cost = (s[i] == t[j])?0:b;
				ll one = arr[ind%2][j]  + a;
				ll two = arr[(ind-1)%2][j+1] + a;
				ll three = arr[(ind-1)%2][j] + cost;
				arr[(ind%2)][j+1] = min(one,min(two,three));
			}
		}
		if(arr[ind%2][t.length()] <= k)
			cout<<arr[ind%2][t.length()]<<endl;
		else
			cout<<-1<<endl;
	}
}