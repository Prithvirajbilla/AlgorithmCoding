#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n1;
		cin>>n1;
		int number = 0;
		while(n1 > 2048)
		{
			n1 = n1 - 2048;
			number++;
		}
		int n = n1;
		while( n > 0)
		{
			int k = n & 1;
			if(k == 1)
				number++;
			n= n >> 1;
		}
		cout<<number<<endl;
	}
}