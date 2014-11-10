#include <bits/stdc++.h>
using namespace std;

int cnt[1005] = {0};
int blankets[1005] = {0};
struct cmp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a.second > b.second;
	}
};
int main()
{
	int n,k;
	cin>>k>>n;
	for (int i = 0; i < k; ++i)
	{
		cin>>blankets[i];
		blankets[i] = (blankets[i] == -1)?0:blankets[i];
		cnt[blankets[i]]++;
	}
	multiset<pair<int,int>,cmp> check;
	for (int i = 1; i <= n; ++i)
	{
		cout<<cnt[i]<<" ";
		if(cnt[i] != 0)
		{
			check.insert(make_pair(i,cnt[i]));
		}
	}
	cout<<endl;
	int cnst = k/n;
	bool b = true;
	while(!check.empty())
	{
		multiset<pair<int,int> >::iterator it = check.begin();
		cout<<it->second<<" "<<it->first<<endl;
		if(it->second > cnst)
		{
			pair<int,int> p1 = make_pair(it->first,it->second-cnst);
			check.erase(it);
			check.insert(p1);
		}
		else if(it->second == cnst)
		{
			check.erase(it);
		}
		else
		{
			int first = it->second;
			int fst_clr = it->first;
			it++;
			if(it != check.end())
			{
				int next = it->second;
				int nxt_clr = it->first;
				if(first+next > cnst)
				{
					pair<int,int> p1 = make_pair(it->first,first+next-cnst);
					check.erase(it);
					it--;
					check.erase(it);
					check.insert(p1);
				}
				else if(first+next == cnst)
				{
					check.erase(it);
					it--;
					check.erase(it);
				}
				else
				{
					if(cnt[0] >= cnst-first-next)
					{
						cnt[0]-=cnst-first-next;
					}
					else
					{
						b = false;
						cout<<"No"<<endl;
						break;
					}
				}
			}
			else
			{
				it--;
				check.erase(it);
			}
		}
	}
	if(b)
	{
		cout<<"Yes"<<endl;
	}

}