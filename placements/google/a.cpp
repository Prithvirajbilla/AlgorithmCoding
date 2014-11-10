#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int cas = 1;
int room[1005][1005] = {0};
int marked[1005][1005] = {0};
int s;
int bfs(int i,int j)
{
	memset(marked,0,sizeof(marked[0][0])*1005*1005);
	queue<pair<int,int> > bf;
	bf.push(make_pair(i,j));
	int res = 0;
	marked[i][j] = 0;
	while(!bf.empty())
	{
		pair<int,int> t = bf.front();
		bf.pop();
		if(t.first+1 < s && marked[t.first+1][t.second] == 0 
			&& room[t.first+1][t.second] == room[t.first][t.second]+1)
		{
			bf.push(make_pair(t.first+1,t.second));
			marked[t.first+1][t.second]=marked[t.first][t.second]+1;
		}
		if(t.first-1 >= 0 && marked[t.first-1][t.second] == 0 
			&& room[t.first-1][t.second] == room[t.first][t.second]+1)
		{
			bf.push(make_pair(t.first-1,t.second));
			marked[t.first-1][t.second]=marked[t.first][t.second]+1;
		}
		if(t.second+1 < s && marked[t.first][t.second+1] == 0 
			&& room[t.first][t.second+1] == room[t.first][t.second]+1)
		{
			bf.push(make_pair(t.first,t.second+1));
			marked[t.first][t.second+1]=marked[t.first][t.second]+1;
		}
		if(t.second-1 >= 0 && marked[t.first][t.second-1] == 0 
			&& room[t.first][t.second-1] == room[t.first][t.second]+1)
		{
			bf.push(make_pair(t.first,t.second-1));
			marked[t.first][t.second-1]=marked[t.first][t.second]+1;
		}
		res = marked[t.first][t.second];
	}
	return res;

}

int main()
{
	int T;
	cin>>T;
	for (int cas = 1; cas <=T ; ++cas)
	{
		memset(room,0,sizeof(room[0][0])*1005*1005);
		cin>>s;
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < s; ++j)
			{
				cin>>room[i][j];
			}
		}
		int m_dist = 0;
		int m_room = 1;
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j <s ; ++j)
			{
				int k = bfs(i,j);
				if(k > m_dist)
				{
					m_dist = k;
					m_room = room[i][j];
				}
				else if( k== m_dist && m_room > room[i][j])
				{
					m_dist = k;
					m_room = room[i][j];
				}
			}
		}
		// cout<<m_dist<<endl;
		printf("Case #%d: %d %d\n",cas,m_room,m_dist+1);
	}
	return 0;
}