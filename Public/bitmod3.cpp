#include <bits/stdc++.h>
using namespace std;
int array[100000];
int n;
int INT_SIZE = 31;
int getSingle()
{
	int result = 0;

	for (int i = 0; i < INT_SIZE; ++i)
	{
		int sum = 0;
		int x = 1 << i;
		for (int j = 0; j < n; ++j)
		{
			if(array[j] & x)
			{
				sum++;
			}
		}
		if(sum%3)
		{
			result |= x;
		}
	}
	return result;
}

int main()
{
	memset(array,0,sizeof(array));
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	cout<<getSingle()<<endl;
	return 0;
}