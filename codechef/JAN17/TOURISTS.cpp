#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll N,E;
pll edges[200005];
vector<map<ll,int> > graph(100005);
set<pair<ll,ll> > edge_check;
int main()
{
	cin>>N>>E;
	for(int i =0; i< E; i++)
	{
		ll a,b;
		cin>>a>>b;
		edges[i] = pll(a,b);
		if(graph[a].find(b) != graph[a].end()){
			graph[a][b] =graph[a][b] + 1;
		}
		else{
			graph[a][b] =  1;
		}

		if(graph[b].find(a) != graph[b].end()){
			graph[b][a] = graph[b][a] + 1;
		}
		else{
			graph[b][a] =  1;
		}

	}
	set<ll> visited;
	ll pick = 1;
	ll is_picked = 0;
	queue<ll> order_visit;
	bool can_happen = true;
	while(is_picked != 1 || visited.size() < N) {
		// cout<<pick<<endl;
		visited.insert(pick);
		order_visit.push(pick);
		ll neighbor = 0;
		for(map<ll,int>::iterator it=graph[pick].begin();it!=graph[pick].end();it++){
			// cout<<it->first<<" "<<it->second<<",";
			if(it->second > 0){
				if(visited.size() == N && graph[pick].find(1) != graph[pick].end()){
					neighbor = 1;
				}
				else{
					neighbor = max(it->first,neighbor);
					if(neighbor > 1)
					break;
				}
			}
		}
		// cout<<endl;
		// cout<<neighbor<<endl;
		if(neighbor == 0){
			can_happen = false;
			break;
		}
		graph[pick][neighbor]--;
		graph[neighbor][pick]--;
		pick = neighbor;
		is_picked = pick;
	}
	if(can_happen){
		if(pick == 1 && visited.size() == N){
			order_visit.push(pick);
			cout<<"YES"<<endl;
			ll f = order_visit.front();
			order_visit.pop();
			while(!order_visit.empty()){
				ll s = order_visit.front();
				order_visit.pop();
				edge_check.insert(pair<ll,ll>(f,s));
				f = s;
			}
			for(int i =0; i <E; i++){
				if(edge_check.find(edges[i]) != edge_check.end()){
					cout<<edges[i].first<<" "<<edges[i].second<<endl;
				}
				else{
					cout<<edges[i].second<<" "<<edges[i].first<<endl;
				}
			}
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}