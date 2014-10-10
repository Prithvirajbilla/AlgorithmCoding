#include <bits/stdc++.h>
using namespace std;
// int array[105];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int* array = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		int max_l = *max_element(array,array+n);
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			ans+= max_l - array[i];
		}
		if(ans == m || (m-ans)%n == 0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}