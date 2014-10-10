#include <bits/stdc++.h>
using namespace std;
int array[100005],prev[30005];
int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>array[i];
	}
	memset(prev,sizeof(prev),0);
	long long int result = 0;
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = i+1; j <= n ; ++j)
		{
			int k = 2*array[i] - array[j];
			if(k >= 1 && k <= 30000)
				result+=prev[k];
		}
		prev[array[i]]++;
	}
	cout<<result<<endl;
	return 0;
}