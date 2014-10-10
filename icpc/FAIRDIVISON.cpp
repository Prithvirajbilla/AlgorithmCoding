#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int t;
ll array[105];
ll answer[105];
struct cmp
{
	bool operator() (pair<ll,int> a, const pair<ll,int> b)
	{
		if(a.first != b.first)
			return a.first > b.first;
		else
		{
			if(a.second != b.second)
			{
				return a.second < b.second;
			}
		}
		return false;
	}
};
int main()
{
	cin>>t;
	while(t--)
	{
		int p,n;
		cin>>p>>n;
		int ideal_distance = p/n;
		memset(array,0,sizeof(array));
		memset(answer,0,sizeof(answer));
		ll sum = 0;
		set<pair<ll,int>,cmp > rr;
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
			sum+=array[i];
			rr.insert(make_pair(array[i],i));
		}
		if(sum < p)
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		int now_n = n;
		while( p > 0 && now_n > 0)
		{
			ideal_distance = p/now_n;
			set<pair<ll,int>,cmp> nn;
			for (set<pair<ll,int> >::iterator it = rr.begin(); it != rr.end(); it++)
			{
				if((*it).first <= ideal_distance)
				{
					answer[(*it).second] += (*it).first;
					p -= (*it).first;
					if(p == 0)
					{
						break;
					}
					nn.insert(make_pair(0,(*it).second));
					now_n--;
				}
				else
				{
					answer[(*it).second] += ideal_distance;
					p -= ideal_distance;
					if(p == 0)
					{
						break;
					}
					nn.insert(make_pair((*it).first-ideal_distance,(*it).second));
				}
			}
			rr = nn;
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<answer[i]<<" ";
		}
		cout<<endl;
	}
}