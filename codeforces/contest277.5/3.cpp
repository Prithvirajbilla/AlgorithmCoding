#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> > graph(3005);
set<int> visited_nodes;
int ans = 0;
int main()
{
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin>>a>>b;
		graph[a-1].push_back(b-1);
	}
	for (int i = 0; i < n; ++i)
	{
		sort(graph[i].begin(),graph[i].end());
	}

	for (int i = 0; i < n; ++i)
	{
		vector<int> ct(n); 
		for (int j = 0; j < graph[i].size(); ++j)
		{
			for(int k=0; k<graph[graph[i][j]].size();k++)
			{
				ct[graph[graph[i][j]][k]]++;
			}
		}
		for (int j = 0; j < n; ++j)
		{
			// cout<<ct[j]<<" ";
			if(ct[j] > 1 && j != i)
				ans += ((ct[j])*(ct[j]-1))/2;
		}
		// cout<<endl;
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;

}