#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int N,K;
ll array[100005];
int main(int argc, char const *argv[])
{
	cin>>N>>K;
	memset(array,sizeof(array),0);
	for (ll i = 1; i <= N; ++i)
	{
		cin>>array[i];
	}
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
			if(num > K)
			{
				break;
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

	return 0;
}