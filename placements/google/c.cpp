#include <bits/stdc++.h>
using namespace std;
int cas = 1;
string src[10005];
string dest[10005];
int sd[10005];
int dd[10005];
set<string> src_dist;
set<string> dest_src;
int main()
{
	int T;
	cin>>T;
	for(int cas =1;cas<=T;cas++)
	{
		int n;
		cin>>n;
		memset(src,0,sizeof(src));
		memset(dest,0,sizeof(dest));
		memset(sd,0,sizeof(sd));
		memset(dd,0,sizeof(dd));
		src_dist.clear();
		dest_src.clear();
		for (int i = 0; i < n; ++i)
		{
			cin>>src[i];	
			cin>>dest[i];
			pair<set<string>::iterator,bool> it = src_dist.insert(src[i]);
			if(it->second == true)
				

		}

	}
}