#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans = n &(n-1);
	cout<<ans<<endl;
	int ans2 = n ^ (n & -n);
	cout<<ans2<<endl;
	return 0;
}