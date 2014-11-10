#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	map<int,map<int,pair<int,int> > > req;
	for (int i = 0; i < n; ++i)
	{
		int id, attr,val,pr;
		cin>>id>>attr>>val>>pr;
		if(req.find(id) != req.end())
		{
			map<int,map<int,pair<int,int> > >::iterator it = req.find(id);
			if(it->second.find(attr) != it->second.end())
			{
				//found
				map<int,pair<int,int> >::iterator it1 = it->second.find(attr);
				if(it1->second.second <= pr)
				{
					it1->second.second = pr;
					it1->second.first = val;
				}
			}
			else
			{
				it->second.insert(pair<int,pair<int,int> >(attr,make_pair(val,pr)));
			}
		}
		else
		{
			map<int,pair<int,int> > sup;
			pair<int,int> v = make_pair(val,pr);
			sup.insert(pair<int,pair<int,int> >(attr,v));
			req.insert(pair<int,map<int,pair<int,int> > >(id,sup));
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int id,attr;
		cin>>id>>attr;
		map<int,map<int,pair<int,int> > >::iterator it = req.find(id);
		map<int,pair<int,int> >::iterator it1 = it->second.find(attr);
		cout<<it1->second.first<<endl;
	}
}