#include <bits/stdc++.h>
using namespace std;
int array[1005] = {0};
int main()
{
	int n,x;
	cin>>n>>x;
	long long int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
		sum+=array[i];
	}
	sum = abs(sum);
	if(sum == 0)
	{
		cout<<0<<endl;
	}
	else if(sum < x)
	{
		cout<<1<<endl;
	}
	else
	{
		if(sum%x == 0)
		{
			cout<<sum/x<<endl;
		}
		else
		{
			cout<<sum/x + 1 <<endl;
		}
	}
	return 0;

}