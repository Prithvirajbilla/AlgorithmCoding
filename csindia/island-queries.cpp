#include <bits/stdc++.h>
using namespace std;
vector<int> pos[200005];
int arr[200005];
// int another[200005];
int main()
{
	int n,q;
	cin>>n>>q;
	memset(arr,0,sizeof(arr));
	memset(pos,0,sizeof(pos));
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		pos[arr[i]].push_back(i);
	}
	for (int i = 0; i < q; ++i)
	{
		int type;
		cin>>type;
		if(type == 1)
		{
			int v1,v2;
			cin>>v1>>v2;
			for (int j = 0; j < pos[v1].size(); ++j)
			{
				arr[pos[v1][j]] = v2;
			}
			for (int j = 0; j < pos[v2].size(); ++j)
			{
				arr[pos[v2][j]] = v1;
			}
			swap(pos[v1],pos[v2]);
		}
		else
		{
			int x;
			cin>>x;
			int ans = 0;
			// memset(another,0,sizeof(another));
			// for (int j = 0; j < n; ++j)
			// {
			// 	if(arr[j] <= x)
			// 		another[j] = 0;
			// 	else
			// 		another[j] = 1;
			// }
			int k = 0;
			while(k < n)
			{
				if((arr[k] <=x) != 0)
				{
					while(k < n && (arr[k] <=x) != 0)
					{
						k++;
					}
					ans++;
				}
				k++;
			}
			cout<<ans<<endl;
		}
	}
}