#include <bits/stdc++.h>
using namespace std;
int n,m,d;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>d;
		multiset<int> l;
		for (int i = 0; i < n; ++i)
		{
			int k;
			cin>>k;
			l.insert(k);
		}
		bool stat = true;
		for (int i = 0; i < m; ++i)
		{

			// multiset<int>:: reverse_iterator it = l.rbegin();
			// cout<<*it<<endl;
			int lk= 0;
			if(!l.empty())
				lk = *l.rbegin();
			if(lk <= d)
			{
				cout<<"NO"<<endl;
				stat = false;
				break;
			}	
			else
			{
				l.erase(--l.end());
				l.insert(lk-d);
			}
		}
		if(stat)
			cout<<"YES"<<endl;
	}
	return 0;
}