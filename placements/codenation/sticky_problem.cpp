#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int l1,u1,l2,u2,l3,u3;
	char c;
	cin>>l1>>c>>u1>>l2>>c>>u2>>l3>>c>>u3;
	int mi = 100000,ma = 0;
	for (int i = l1; i <= u1 ; ++i)
	{
		for(int j = l2; j<= u2; j++)
		{
			for(int k=l3; k<= u3;k++)
			{
				int bs = abs(k-j);
				int val = sqrt(bs*bs+i*i);
				mi = min(mi,val);
				ma = max(ma,val);
			}
		}
	}
	if(mi)
	cout<<mi<<","<<ma<<endl;

	return 0;
}