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
	sort(array,array+n);
	for (int i = 0; i < n; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	int no_piles = 1;
	int cap = array[n-1];
	for (int i = n-2; i >= 0 ; i--)
	{
		if(cap == 0)
		{
			no_piles++;
			cap = array[i];
		}
		else
		{
			cap = min(cap-1,array[i]);
		}
	}
	cout<<no_piles<<endl;
	return 0;
}