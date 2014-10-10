#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	cin>>x;
	int  count = 0;
	while(x > 0)
	{
		x = x &(x-1);
		// 011 010 010
		count++;
	}
	cout<<count<<endl;
	return 0;
}