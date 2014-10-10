#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int x[100];
	long long int y[100];
	int v[100];
	int N;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>x[i]>>y[i]>>v[i];
	}
	int min = 2147483647;
	int small;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j <N ; ++j)
		{
			long long int x1 = x[i];
			long long int y1 = y[i];
			long long int x2 = x[j];
			long long int y2 = y[j];
			int right = 0;
			int left = 0;
			for (int k = 0; k < N; ++k)
			{
					long long int s = (x2-x1)*(y[k]-y1)-((x[k]-x1)*(y2-y1));
					if(s <= 0)
					{
						right+=v[k];
					}
					else
					{
						left+=v[k];
					}
			}
			if(abs(left-right) <  min)
			{
				min = abs(left-right);
				if(left < right)
					small = left;
				else
					small = right;
			}
		}
		for (int j = i+1; j <N ; ++j)
		{
			long long int x1 = x[i];
			long long int y1 = y[i];
			long long int x2 = x[j];
			long long int y2 = y[j];
			int right = 0;
			int left = 0;
			for (int k = 0; k < N; ++k)
			{
					long long int s = (x2-x1)*(y[k]-y1)-((x[k]-x1)*(y2-y1));
					if(s < 0)
					{
						right+=v[k];
					}
					else
					{
						left+=v[k];
					}
			}
			if(abs(left-right) <  min)
			{
				min = abs(left-right);
				if(left < right)
					small = left;
				else
					small = right;
			}
		}

	}
	cout<<small<<endl;
}