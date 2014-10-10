#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int* petrol = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>petrol[i];
	}
	int* distance = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>distance[i];
	}
	int change = 0,where;
	for (int i = 0; i < n; ++i)
	{
		if(petrol[i] < distance[i])
		{
			change = petrol[i] - distance[i];
			where = i;
			break;
		}
	}
	if(change == 0)
	{
		cout<<0<<endl;
		return -1;
	}
	where -= 1;
	while(change < 0)
	{
		if(where < 0)
		{
			where+=n;
		}
		change += petrol[where] - distance[where];
		where--;
	}
	cout<<where<<endl;
	return 0;

}