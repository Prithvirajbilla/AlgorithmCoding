#include <bits/stdc++.h>
using namespace std;
int a[100005] = {0};
int main()
{
	int N,T;
	cin>>N>>T;
	for (int i = 0; i < N; ++i)
		cin>>a[i];
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		cout<<*min_element(a+m,a+n+1)<<endl;
	}
	return 0;
}