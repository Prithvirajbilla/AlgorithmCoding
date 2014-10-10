#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll l[100005],a[100005];
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>l[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int q;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		int type;
		cin>>type;
		if(type == 1)
		{
			int c;ll d;
			cin>>c>>d;
			a[c-1] = d;
		}
		else if(type == 2)
		{
			int e;
			cin>>e;
			e=e-1;
			ll current_state = 0;
			for (int i = e; i < n; ++i)
			{
				if(current_state+a[e] >= l[e])
				{
					current_state = (current_state+a[e])-l[e];
				}
				else 
				{
					cout<<i+1<<endl;
					break;
				}
			}
		}
	}
	return 0;
}