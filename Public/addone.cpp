#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	int ans = 1;
	while(t & ans) //0 is false
	{
		t = t^ans;
		ans<<=1;
	}
	t = t^ans;
	cout<<t<<endl;
	return 0;
}