#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
ll powers[64];
int main()
{
	powers[0] = 1;
	for (int i = 1; i < 64; ++i)
	{
		powers[i] = powers[i-1]*2;
	}
/*	for (int i = 0; i < 63; ++i)
	{
		cout<<powers[i]<<" ";
	}
	cout<<endl;
*/	int T;
	cin>>T;
	while(T--)
	{
		ll N;
		cin>>N;
		ll number_of_operations = 0;
		while(N != 1)
		{
			for(int i= 0; i < 64; i++)
			{
				if(powers[i] > N)
				{
					N -= powers[i-1];
					number_of_operations++;
					break;
				}
				else if(powers[i] == N)
				{
					N = powers[i-1];
					number_of_operations++;
					break;
				}
			}
			if(N > powers[63])
				N -= powers[63];
		}
/*		cout<<number_of_operations<<endl;
*/		if(number_of_operations%2 == 0)
			cout<<"Richard"<<endl;
		else
			cout<<"Louise"<<endl;
	}
}