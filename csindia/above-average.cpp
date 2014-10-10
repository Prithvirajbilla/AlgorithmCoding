#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		memset(arr,0,sizeof(arr));
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			sum+=arr[i];
		}
		double avg = sum;
		avg /= n;
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if(arr[i] > avg)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}