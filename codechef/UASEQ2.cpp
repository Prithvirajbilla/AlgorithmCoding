#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int N,K;
ll array[100005];
void solve100()
{
	ll first = 1000000000;
	ll diff = 1000000000;
	for (ll i = 2; i <= N ; ++i)
	{
		ll d = array[i] - array[i-1];
		ll a = (array[i-1]*(i-1)) - ((i-2)*array[i]);
		if(a > first)
		{
			continue;
		}
		else if(a == first && d > diff)
		{
			continue;
		}
		ll num = 0;
		for (ll j = 1; j <= N ; ++j)
		{
			if(a+(j-1)*d != array[j])
			{
				num++;
			}
		}
		if(num <= K)
		{
			first = a;
			diff = d;
		}
	}
	for (ll i = 1; i <= N; ++i)
	{
		array[i] = first+(i-1)*diff;
	}
	for (ll i = 1; i <= N ; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;

}
void solvea100()
{
	//only one ap is possible,
	//let's just find the d:
	int d = 0, fr = 0;
	map<int,int> freq;
	for (int i = 2; i <= N; ++i)
	{
		int diff = array[i] - array[i-1];
		map<int,int>:: iterator lb = freq.lower_bound(diff);
		if(lb != freq.end() && !(freq.key_comp()(diff, lb->first)))
		{
			freq[diff]++;
		}
		else
		{
			freq.insert(pair<int,int>(diff,1));
		}
	}
	for (map<int,int>::iterator it = freq.begin();it != freq.end(); it++)
	{
		// cout<<it->first<<" "<<it->second<<endl;
		if(it->second > fr)
		{
			fr = it->second;
			d = it->first;
		}
	}
	// cout<<d<<endl;
	//found the fucking d
	int first = 0;
	for (int i = 1; i <= K+1 ; ++i)
	{
		int a = array[i]-((i-1)*d);
		int num = 0;
		for(int j = 1; j<= N; j++)
		{
			if(a+(j-1)*d != array[j])
			{
				num++;
			}
			if(num > K)
			{
				break;
			}
		}
		if(num <= K)
		{
			first = a;
		}
	}
	for (int i = 1; i <= N ; ++i)
	{
		cout<<first+(i-1)*d<<" ";
	}
	cout<<endl;
}
int main()
{
	cin>>N>>K;
	memset(array,sizeof(array),0);
	for (ll i = 1; i <= N; ++i)
	{
		cin>>array[i];
	}
	if(N <= 0)
	{
		solve100();
	}
	else
	{
		solvea100();
	}
	return 0;
}