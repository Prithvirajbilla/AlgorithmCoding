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
	vector<int> ans;
	for (int i = 0; i < n-1; ++i)
	{
		if(array[i] > array[i+1])
		{
			ans.push_back(i);
		}
	}

}