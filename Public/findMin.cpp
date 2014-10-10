#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y;
	cin>>x>>y;
	int k3 = (x-y)>>31;
/*	bitset<32> kk(k3);
	bitset<32> xk(x);
	bitset<32> yk(y);
	cout<<xk.to_string()<<" "<<yk.to_string()<<endl;
	bitset<32> xy(x-y);
	cout<<xy.to_string()<<endl;
	cout<<kk.to_string()<<endl;
	cout<<k3<<endl;
*/	int k2 = ((x-y) & k3);
	int result = y + ((x-y) & (x-y)>>31);
	cout<<result<<endl;
	return 0;
}