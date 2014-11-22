#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int res = 0;
	int l =0;
	while(n > 0)
	{
		if(!(n&1))
		{
			res|=(1<<l);
		}
		n = n/2;
		l++;
	}
	cout<<res<<endl;

}