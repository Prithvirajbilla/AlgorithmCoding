 #include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

const int maxnodes = 1000005;
const int maxedges = 1000005;

// graph
int edges;
int last[maxnodes], head[maxedges], previous[maxedges], len[maxedges];
int prio[maxnodes], pred[maxnodes];

void graphClear() {
    fill(last, last + maxnodes, -1);
    edges = 0;
}

void addEdge(int u, int v, int length) {
    head[edges] = v;
    len[edges] = length;
    previous[edges] = last[u];
    last[u] = edges++;
}

// heap
int h[maxnodes];
int pos2Id[maxnodes];
int id2Pos[maxnodes];
int hsize;

void hswap(int i, int j) {
    swap(h[i], h[j]);
    swap(pos2Id[i], pos2Id[j]);
    swap(id2Pos[pos2Id[i]], id2Pos[pos2Id[j]]);
}

void moveUp(int pos) {
    while (pos > 0) {
        int parent = (pos - 1) >> 1;
        if (h[pos] >= h[parent]) {
            break;
        }
        hswap(pos, parent);
        pos = parent;
    }
}

void add(int id, int prio) {
    h[hsize] = prio;
    pos2Id[hsize] = id;
    id2Pos[id] = hsize;
    moveUp(hsize++);
}

void increasePriority(int id, int prio) {
    int pos = id2Pos[id];
    h[pos] = prio;
    moveUp(pos);
}

void moveDown(int pos) {
    while (pos < (hsize >> 1)) {
        int child = 2 * pos + 1;
        if (child + 1 < hsize && h[child + 1] < h[child]) {
            ++child;
        }
        if (h[pos] <= h[child]) {
            break;
        }
        hswap(pos, child);
        pos = child;
    }
}

int removeMin() {
    int res = pos2Id[0];
    int lastNode = h[--hsize];
    if (hsize > 0) {
        h[0] = lastNode;
        int id = pos2Id[hsize];
        id2Pos[id] = 0;
        pos2Id[0] = id;
        moveDown(0);
    }
    return res;
}

void dijkstra(int s) {
    fill(pred, pred + maxnodes, -1);
    fill(prio, prio + maxnodes, INT_MAX);
    prio[s] = 0;
    hsize = 0;
    add(s, 0);

    while (hsize) {
        int u = removeMin();
        for (int e = last[u]; e >= 0; e = previous[e]) {
            int v = head[e];
            int nprio = prio[u] + len[e];
            if (prio[v] > nprio) {
                if (prio[v] == INT_MAX)
                    add(v, nprio);
                else
                    increasePriority(v, nprio);
                prio[v] = nprio;
                pred[v] = u;
            }
        }
    }
}

int main() {
    graphClear();
/*    addEdge(1, 2, 1);
    addEdge(2, 1, 100);
    addEdge(3,2,1);
    addEdge(2,3,100);
    addEdge(3,4,1);
    addEdge(4,3,100);
    addEdge(7,4,1);
    addEdge(4,7,100);
    addEdge(6,2,1);
    addEdge(2,6,1);
    addEdge(5,6,1);
    addEdge(6,5,100);
    addEdge(7,5,1);
    addEdge(5,7,100);
*//*    for (int i = 0; i < edges; ++i)
    {
    	cout<<head[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < edges; ++i)
    {
    	cout<<len[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < edges; ++i)
    {
    	cout<<previous[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 7; ++i)
    {
    	cout<<last[i]<<" ";
    }
    cout<<endl;
*/
   int n,m;
   cin>>n>>m;
   for (int i = 0; i < m; ++i)
   {
   		int a,b;
   		cin>>a>>b;
   		if(a == b)
   			continue;
   		addEdge(a,b,0);
   		addEdge(b,a,1);
   }

    dijkstra(1);
    if(prio[n] == INT_MAX)
    	cout<<-1<<endl;
    else 
    	cout<<prio[n]<<endl;
}