#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	bitset<32> nk(n);
	cout<<nk<<endl;

	int rightmostbit = n & -n;

	int nexthighestbit = n + rightmostbit;
	nexthighestbit /= rightmostbit;
	nexthighestbit >>=2; //adjusting stuff
	int next = n + rightmostbit;
	next = next | nexthighestbit ;
	cout<<next<<endl;
	bitset<32> a(next);
	cout<<a<<endl;
	return 0;

}