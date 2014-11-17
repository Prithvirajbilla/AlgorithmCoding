#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll in[3005] = {0};
ll temp[3005] = {0};
vector<pair<int,int> >  swaps;
int n;
void solve(int i)
{
	if(i == n)
		return ;
	if(in[i] != temp[i])
	{
		for(int k=i+1; k<n;k++)
		{
			if(in[k] == temp[i])
			{
				swaps.push_back(make_pair(i,k));
				swap(in[i],in[k]);
				break;
			}
		}
	}
	solve(i+1);
}
int main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>in[i];
		temp[i] = in[i];
	}

	sort(temp,temp+n);

	solve(0);
	cout<<swaps.size()<<endl;
	for (int i = 0; i < swaps.size(); ++i)
	{
		cout<<swaps[i].first<<" "<<swaps[i].second<<endl;
	}
	return 0;
}