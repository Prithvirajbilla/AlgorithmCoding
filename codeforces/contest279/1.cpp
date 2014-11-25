#include <bits/stdc++.h>
using namespace std;
int a[200010] = {0};
int main()
{
	int n;
	cin>>n;
	
	map<int,int> f,b;
	for (int i = 0; i < n; ++i)
	{
		int p,q;
		cin>>p>>q;
		f[p] = q;
		b[q] = p;
	}

	if(n%2 == 0)
	{	

		int st = 0;
		int count = 0;
		while(f.find(st) != f.end())
		{
			a[count] = st;
			st = f[st];
			count+=2;
		}
		a[count] = st;

		st = 0;
		count = n+1;
		while(b.find(st) != b.end())
		{
			a[count] = st;
			st = b[st];
			count-=2;
		}
		a[count] = st;
	}
	else
	{
		int st = 0;
		int count = 0;
		while(f.find(st) != f.end())
		{
			a[count] = st;
			int temp = f[st];
			f.erase(st);
			st = temp;
			count+=2;
		}
		a[count] = st;
		
		//st = f.begin()->first;
		set<int> a1,a2;
		for (map<int,int>::iterator it=f.begin();it!=f.end();it++)
		{
			a1.insert(it->first);
			a2.insert(it->second);
			// cout<<it->first<<" "<<it->second<<endl;
		}
		vector<int> v(10);
		set_difference(a1.begin(),a1.end(),a2.begin(),a2.end(),v.begin());
		// for (int i = 0; i < 10; ++i)
		// {
		// 	cout<<v[i]<<" ";
		// }
		// cout<<endl;
		st = v[0];
		count = 1;
		
		while(f.find(st) != f.end())
		{
			// cout<<st<<endl;
			a[count] = st;
			st = f[st];
			count+=2;
		}
		a[count] = st;
	
	}
	for (int i = 1; i <= n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}