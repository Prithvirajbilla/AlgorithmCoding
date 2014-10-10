#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int* array = new int[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		cin>>array[i];
	}
	int** lookup = new int*[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		lookup[i] = new int[n+1];
		for (int j = 0; j < n+1; ++j)
		{
			lookup[i][j] = 2;
		}
	}
	int max_ap = 2;
	for (int i = n-1; i >= 1 ; i--)
	{
		int j = i--;
		int k = i++;
		while(j >= 1 && k <= n)
		{
			int val = array[j] + array[k] - (2*array[i]);
			if(val > 0)
			{
				j--;
			}
			else if(val < 0)
			{
				k++;
			}
			else
			{
				lookup[j][i] = lookup[i][k] + 1;
				max_ap = max(lookup[j][i],max_ap);
				j--;
				k++;
			}
		}
	}
	cout<<max_ap<<endl;
	
	return 0;
}