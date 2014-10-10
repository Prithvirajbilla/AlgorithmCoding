#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 100
ll modulos(ll a, ll b)
{
	if(a < 0)
	{
		return (b - abs(a)%b)%b;
	}
	else
	{
		return a%b;
	}

}
ll powermod(ll a, ll b)
{
	ll res = 1;
	vector<ll> st;
	ll m = b;
	while(b--)
	{
		res *= a;
		res %= mod;
		int index = find(st.begin(), st.end(), res) - st.begin();
		bool isPresent = find(st.begin(), st.end(), res) != st.end();
		if (isPresent)
		{
			// for (int i = 0; i < st.size(); ++i)
			// {
			// 	cout<<st[i]<<" ";
			// }
			// cout<<endl;
			// cout<<index<<endl;
			int sz = st.size();
			// cout<<st.size()<<endl;
			int km = m - index;
			int final = km%(st.size()-index);
			if (index == 0)
				final = modulos(final-1,st.size());
			else
			{
				final = modulos(final-1,st.size()-index);
				final += index;
			}
			// cout<<st[final]<<endl;
			return st[final];
		}
		st.push_back(res);
	}
	return res;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>k>>n;
		ll quo = k/100;
		ll rem = k%100;
		ll result = 0;
		for(int i=1; i<=99;i++)
		{
			if(i <= rem)
				result += (quo+1)*powermod(i,n);
			else
				result += (quo)*powermod(i,n);
			result %= mod;
			// cout<<result<<endl;
		}
		result %= mod;
		if(result == 0)
			cout<<"00"<<endl;
		else if(result < 10)
			cout<<"0"<<result<<endl;
		else 
			cout<<result<<endl;
	}
}