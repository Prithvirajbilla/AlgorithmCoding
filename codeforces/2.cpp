#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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
	if(ans.size() > 1)
	{
		cout<<-1<<endl;
	}
	else if(ans.size() == 0)
	{
		cout<<0<<endl;
	}
	else
	{
		vector<int> check;
		for(int i =ans[0]+1; i < n; i++)
		{
			check.push_back(array[i]);
		}
		for (int i = 0; i < ans[0]+1; ++i)
		{
			check.push_back(array[i]);
		}
/*		for (int i = 0; i < n; ++i)
		{
			cout<<check[i]<<" ";
		}
		cout<<endl;
*/		bool c = false;
		for (int i = 0; i < n-1; ++i)
		{
			if(check[i] <= check[i+1])
			{
				continue;
			}
			else
			{
				cout<<-1<<endl;
				c = true;
				break;
			}
		}
		if(c == false)
		cout<<n-(ans[0]+1)<<endl;
	}
	return 0;
}