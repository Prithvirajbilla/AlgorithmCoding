#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105] = {0};
int b[105] = {0};
int ans = 0;
void solve(int i,int j)
{
	if(i == n || j == m)
		return ;
	if(abs(a[i]-b[j]) <= 1)
	{
		solve(i+1,j+1);
		ans++;
	}
	else if(a[i] > b[j])
	{
		solve(i,j+1);
	}
	else if(a[i] < b[j])
	{
		solve(i+1,j);
	}
}
int main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+m);
	solve(0,0);
	cout<<ans<<endl;
}