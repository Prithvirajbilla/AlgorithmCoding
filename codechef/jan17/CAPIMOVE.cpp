#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int N;
ll P[50005];
vector<int> graph[50005];
int main()
{
	cin>>T;
	while(T--)
	{
		map<ll,int> invPop;
		memset(graph, 0, sizeof(graph));

		memset(P, 0, sizeof(P));
		cin>>N;
		vector<ll> que;
		for(int i=1; i<= N; i++)
		{
			cin>>P[i];
			que.push_back(P[i]);
			invPop.insert(pair<ll,int>(P[i],i));
		}
		for(int i = 0; i< N-1; i++){
			int a,b;
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		sort(que.begin(),que.end());
		for(int i = 1; i<= N; i++){
			if(graph[i].size()+1 == N) {
				cout<<0<<endl;
			}
			else{
				priority_queue<ll> small_queue;
				small_queue.push(P[i]);
				for(int j=0; j< graph[i].size(); j++){
					small_queue.push(P[graph[i][j]]);
				}
				int start = N-1;
				while(!small_queue.empty() && small_queue.top() == que[start]){
					small_queue.pop();
					start--;
				}
				cout<<invPop[que[start]]<<endl;
			}
		}

	}
	return 0;
}