#include <bits/stdc++.h>
using namespace std;
int array[200005] = {0};
int cum2k[200005] = {0};
int cum1k[200005] = {0};
int main()
{
	int n,k;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}

	if(n <= 2*k)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum+=array[i];
		}
		cout<<sum<<endl;
	}
	else
	{
		for (int i = 0; i < 2*k; ++i)
		{
			cum2k[0]+=array[i];
		}
		for (int i = 1; i < n-2*k+1; ++i)
		{
			cum2k[i] = cum2k[i-1]+array[i+2*k-1]-array[i-1];
		}
		sort(cum2k,cum2k+n-2*k+1);
		int first = cum2k[n-2*k];

		for (int i = 0; i < k; ++i)
		{
			cum1k[0]+=array[i];
		}
		for (int i = 1; i < n-k+1; ++i)
		{
			cum1k[i] = cum1k[i-1]+array[i+k-1]-array[i-1];
		}
		int pos = max_element(cum1k,cum1k+n-k+1)-cum1k;
		int second = *max_element(cum1k,cum1k+n-k+1);
		for (int i = 0; i < k; ++i)
		{
			array[i+pos] = 0;
		}
		memset(cum1k,0,sizeof(cum1k));
		for (int i = 0; i < k; ++i)
		{
			cum1k[0]+=array[i];
		}
		for (int i = 1; i < n-k+1; ++i)
		{
			cum1k[i] = cum1k[i-1]+array[i+k-1]-array[i-1];
		}
		second+=*max_element(cum1k,cum1k+n-k+1);
		cout<<max(first,second)<<endl;
	}

}