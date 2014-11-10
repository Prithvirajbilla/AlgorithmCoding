#include <bits/stdc++.h>
using namespace std;
int array[2005] = {0};
int cum[2005] = {0};
int main()
{
	int n;
	cin>>n;
	for(int i=0; i< n; i++)
	{
		cin>>array[i];
	}
	sort(array,array+n);
	int sum = 0;
	int max_so_far = 0;
	for (int i = 0; i < n; ++i)
	{
		sum+=array[i];
		if(upper_bound(array,array+n,sum) != array+n)
		{
			int k = (upper_bound(array,array+n,sum) == array+i)?0:1;
			max_so_far = max(max_so_far,i+1+k);
		}
		else
		{
			if(sum == array[n-1])
			{
				int k =(n == 1)?0:1;
				max_so_far = max(max_so_far,i+1+k);
			}
		}
	}
	cout<<max_so_far<<endl;
	return 0;
}