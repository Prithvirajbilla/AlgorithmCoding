#include <bits/stdc++.h>
using namespace std;
map<int,pair<int,int> > a;
int max_x = 0,mi_x = 0,ma_y = 0, mi_y = 0;
multiset<int> ax,ay;
int q;

int main()
{
	int ans = 0;
	cin>>q;
	int add_query = 1;
	while(q--)
	{
		char c; int x,y;
		cin>>c;
		if(c == '+')
		{
			cin>>x>>y;
			x = x^ans;
			y = y^ans;
			a.insert(make_pair(add_query,make_pair(x,y)));
			add_query++;

		}
		else if(c == '-')
		{
			cin>>x;
			x = x^ans;
			a.erase(x);
		}
		else if(c == '?')
		{
			
		}
	}
}