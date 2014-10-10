#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,i,j,n;
	cin>>a>>i>>j>>n;

	int k1 = (a>>i)&((1<<n)-1);
	int k2 = (a>>j)&((1<<n)-1);
	int p= (k1 << i) | (k2 <<j);
	int na = a ^ p;
	int pn = (k1 << j) | (k2 <<i);
	int res = na | pn;
	cout<<res<<endl;
	return 0;
}