#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,int> st,en;
int array[1000005];
int st_array[1000005];
int end_array[1000005];
int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <=n; ++i)
	{
		cin>>array[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		if(st.find(array[i]) != st.end())
		{
			st[array[i]]++;
			st_array[i] = st[array[i]];
		}
		else
		{
			st.insert(pair<ll,int>(array[i],1));
			st_array[i] = 1;
		}
	}
	for (int i = n; i >= 1; i--)
	{
/*		if(en.find(array[i]) != en.end())
		{
			en[array[i]]++;
			end_array[i] = en[array[i]];
		}
		else
		{
			en.insert(pair<ll,int>(array[i],1));
			end_array[i] = 1;
		}
*/		end_array[i] =  st[array[i]] - st_array[i] + 1;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
	{

		for(int j = i+1; j<= n;j++)
		{   
			if(st_array[i] > end_array[j])
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;

}