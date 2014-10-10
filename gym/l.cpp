#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define spacing(i) while(i--) cout<<" "
pair<ll,ll> array[50005];
struct on_first
{
	bool operator()(const pair<ll,ll>& f,const pair<ll,ll>& s)
	{
		if(f.first == s.first)
		{
			return f.second < s.second ;
		}
		else
		{
			return f.first < s.first;
		}
	}
};

struct on_second
{
	bool operator()(const pair<ll,ll>& f,const pair<ll,ll>& s)
	{
		if(f.second == s.second)
		{
			return f.first < s.first;
		}
		else
		{
			return f.second < s.second;
		}
	}
};
int main()
{
	int n;
	cin>>n;
	memset(array,0,sizeof(array));
	for (int i = 0; i < n; ++i)
	{
		ll a,b;
		cin>>a>>b;
		array[i] = make_pair(a,b);
	}

	sort(array,array+n,on_first());

	int current_weight = array[0].first;
	ll max_risk1 = 0,max_risk2 = 0;
	ll tot_risk1 = 0,tot_risk2 = 0;
	for (int i = 1; i < n; ++i)
	{
		int risk = - array[i].second + current_weight;
		if(risk > max_risk1)
			max_risk1 = risk;
		current_weight+=array[i].first;
		if(risk > 0)
			tot_risk1+=risk;
	}
	sort(array,array+n,on_second());
	current_weight = array[0].first;
	for (int i = 1; i < n; ++i)
	{	
		int risk = - array[i].second + current_weight;
		if(risk > max_risk2)
			max_risk2 = risk;
		current_weight+=array[i].first;
		if(risk > 0)
			tot_risk2+=risk;
	}
	cout<<min(max_risk1,max_risk2)<<endl;
	return 0;
}