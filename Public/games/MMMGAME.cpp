#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int* array = new int[n];
		bool g = false;
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
			if(array[i] > 1)
				g = true;
		}
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum ^= (array[i]);
		}
		if((sum == 0 && g) || (sum == 1 && !g) )
		{
			cout<<"Brother"<<endl;
		}
		else
		{
			cout<<"John"<<endl;
		}
	}
}