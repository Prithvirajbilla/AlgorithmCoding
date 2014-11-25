#include <bits/stdc++.h>
using namespace std;
set<int> a,b,c;
int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin>>k;
		if(k == 1)
		{
			a.insert(i);
		}
		else if(k == 2)
		{
			b.insert(i);
		}
		else
		{
			c.insert(i);
		}
	}
	int tf = min(a.size(),min(b.size(),c.size()));
	cout<<tf<<endl;
	for (int i = 0; i < tf; ++i)
	{
		cout<<*a.begin()<<" "<<*b.begin()<<" "<<*c.begin()<<endl;
		a.erase(a.begin());
		b.erase(b.begin());
		c.erase(c.begin());
	}
	return 0;
}