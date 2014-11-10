#include <bits/stdc++.h>
using namespace std;
char graph[55][55];
vector<pair<int,int> > edges_list;
int ans_count = 0;
bool is_matching(int k)
{
	set<int> check_list;
	ans_count = 0;
	int count = 0;
	while(k > 0)
	{
		if(k&1)
		{
			int a = edges_list[count].first,b =edges_list[count].second;
			if(check_list.find(a) != check_list.end())
				return false;
			if(check_list.find(b) != check_list.end())
				return false;
			check_list.insert(a);check_list.insert(b);
			ans_count++;
		}
		k = k >>1;
		count++;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>graph[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(graph[i][j] == 'Y')
			{
				edges_list.push_back(make_pair(i,j));
				// cout<<i<<" "<<j<<endl;
			}
		}
	}
	if(edges_list.size() <= 18)
	{
		// cout<<edges_list.size()<<endl;
		int start = 1<<edges_list.size();
		start--;
		// cout<<start<<endl;
		while(!is_matching(start))
		{
			start--;
		}
		// cout<<start<<endl;
		cout<<ans_count*2<<endl;
	}

}