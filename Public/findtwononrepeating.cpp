#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int* array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	int xr = 0;
	for (int i = 0; i < n; ++i)
	{
		xr ^= array[i];
	}
	int rightmostset = xr & (-xr);
	int x=0,y=0;
	for (int i = 0; i < n; ++i)
	{
		if(array[i] & rightmostset)
			x ^= array[i];
		else
			y ^= array[i];
	}
	cout<<x<<" "<<y<<endl;
	return 0;

}