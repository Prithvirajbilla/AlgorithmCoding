#include <bits/stdc++.h>
using namespace std;
int getLeftMost(int n)
{
	int m = 0;
	while(n > 1)
	{
		n = n>>1;
		m++;
	}
	return m;
}
int count(int n)
{
	if(n < 1)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		int l = getLeftMost(n);
		int ans = l*(pow(2,l-1));
		int new_n = n&(~(1<<l));
		int extra = n- (1<<l)+1;
		return ans + count(new_n)+ extra;
	}
}

int main()
{
	int n;
	cin>>n;
	cout<<count(n)<<endl;

}