#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	cin>>x;
	int mask  = x>>31;
	bitset<32> x1(mask);
	bitset<32> x2(x);
	cout<<x1<<endl;
	cout<<x2<<endl;
	bitset<32> x3(x+mask);
	cout<<x3<<endl;
	int ab = (x+mask) ^ mask;
	cout<<ab<<endl;
	return 0; 
}