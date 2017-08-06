#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
vector<vector<int> > tree(200005);
int indices[200005];
int visited[200005];
int check[200005];
ll ans = 0;

void dfs(int v) {
	for(int i =0; i<tree[v].size(); i++){
		if(check[indices[tree[v][i]]] == 0 && visited[tree[v][i]] == 0) {
			ans++;
			check[indices[tree[v][i]]] = 1;
			visited[tree[v][i]] =1;
			dfs(tree[v][i]);
			check[indices[tree[v][i]]] = 0;
			visited[tree[v][i]] =0;
		}
	}
}

int main() {
	cin>>n;
	memset(indices, 0, sizeof indices);

	for(int i=1; i<= n-1; i++) {
		int p;
		cin>>p;
		tree[i+1].push_back(p);
		tree[p].push_back(i+1);
	}

	// for(int i =1; i<= n; i++) {
	// 	cout<<i<<": ";
	// 	for(int j=0; j< tree[i].size(); j++ ){
	// 		cout<<tree[i][j]<<", ";
	// 	}
	// 	cout<<endl;
	// }

	for (int i = 1; i < n+1; ++i)
	{
		cin>>indices[i];
	}

	for(int i =1; i<= n; i++) {
		memset(visited, 0, sizeof visited);
		memset(check, 0, sizeof check);

		visited[i] = true;
		check[indices[i]] = 1;
		ans++;
		dfs(i);
	}
	cout<<ans<<endl;
}