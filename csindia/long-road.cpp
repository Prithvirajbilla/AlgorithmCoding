#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int l[100005],a[100005];
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
int main()
{
	int n;
	// cin>>n;
	inp(n);
	for (int i = 0; i < n; ++i)
	{
		// cin>>l[i];
		inp(l[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		// cin>>a[i];
		inp(a[i]);
	}
	int q;
	// cin>>q;
	inp(q);
	for (int i = 0; i < q; ++i)
	{
		int type;
		// cin>>type;
		inp(type);
		if(type == 1)
		{
			int c, d;
			// cin>>c>>d;
			inp(c);inp(d);
			a[c-1] = d;
		}
		else if(type == 2)
		{
			int e;
			// cin>>e;
			inp(e);
			e=e-1;
			ll current_state = 0;
			bool now = true;
			for (int i = e; i < n; ++i)
			{
				if(current_state+a[i] >= l[i])
				{
					current_state = (current_state+a[i])-l[i];
				}
				else 
				{
					now = false;
					cout<<i+1<<endl;
					break;
				}
			}
			if(now)
				cout<<n+1<<endl;
		}
	}
	return 0;
}