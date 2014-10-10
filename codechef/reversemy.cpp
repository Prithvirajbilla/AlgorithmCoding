#include <bits/stdc++.h>
using namespace std;
const int MAXINT = 1000000000;
struct head
{
	int node_id;
	int cost;
	head(int n,int i)
	{
		node_id = n;
		cost = i;
	}
};
map<int,vector<head> > graph;
int dist[1000005];
int previous[1000005];
set<head> Queue;

bool operator<(const head &left,const head &right)
{
	if(left.cost != right.cost) return left.cost < right.cost;
	else
	{
		return left.node_id < right.node_id;
	}
}
int nodes;
int edges;
void addEdge(int a,int b,int c)
{
	if(graph.find(a) != graph.end())
	{
		//found something
		graph[a].push_back(head(b,c));
	}
	else
	{
		vector<head> v;
		v.push_back(head(b,c));
		graph.insert(pair<int,vector<head> >(a,v));
	}
}
void djikstra()
{
	dist[1] = 0;
	Queue.insert(head(1,0));
	for(int i=2; i<= nodes; i++)
	{
		dist[i] = MAXINT;
		previous[i] = -1;
		head h(i,dist[i]);
		Queue.insert(h);
	}

	while (!Queue.empty())
	{
		head h = *(Queue.begin());
		Queue.erase(h);
		vector<head> vcl = graph.find(h.node_id)->second;
/*		cout<<h.node_id<<" : ";
*/		for(int i=0; i< vcl.size();i++)
		{
/*			cout<<vcl[i].node_id<<" , ";
*/			int alt =  dist[h.node_id]+vcl[i].cost;
			if(alt < dist[vcl[i].node_id])
			{
				dist[vcl[i].node_id] = alt;
				previous[vcl[i].node_id] = h.node_id;
				Queue.erase(vcl[i]);
				Queue.insert(head(vcl[i].node_id,alt));
			}
		}
/*		cout<<endl;
*/	}

}
int main()
{
	int n,m;
   cin>>nodes>>edges;
   n = nodes;
   m = edges;
   for (int i = 0; i < m; ++i)
   {
   		int a,b;
   		cin>>a>>b;
   		if(a == b)
   			continue;
   		addEdge(a,b,0);
   		addEdge(b,a,1);
   }
    djikstra();
/*   	for (int i = 1; i <= n; ++i)
   	{
   		cout<<dist[i]<<" ";
   	}
   	cout<<endl;
*/    if(dist[n] == MAXINT)
    	cout<<-1<<endl;
    else 
    	cout<<dist[n]<<endl;


}