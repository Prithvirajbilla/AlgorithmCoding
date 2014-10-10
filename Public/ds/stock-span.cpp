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
	stack<int> span;
	int* ret = new int[n];
	ret[0] = 1;
	int i = 1;
	span.push(0);
	while(i < n)
	{
		if(array[span.top()] >  array[i])
		{
			ret[i] = i - span.top();
			span.push(i);
		}
		else
		{
			while(!span.empty() && array[span.top()] < array[i])
			{
				span.pop();
			}
			if(span.empty())
			{
				ret[i] = 1;
				span.push(i);
			}
			else
			{
				ret[i] = i - span.top();
				span.push(i);
			}
		}
		i++;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<ret[i]<<" ";
	}
	cout<<endl;
}