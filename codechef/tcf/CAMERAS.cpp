#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll A[100005] = {0};
pair<ll,ll> B[100005];
int main()
{
	int n,k;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	memset(B,0,sizeof(B));
	for (int i = 0; i < k; ++i)
	{
		ll a,b;
		cin>>a>>b;
		B[i] = make_pair(a,b);
	}
	sort(A,A+n);
	sort(B,B+k);
	ll result  = 0;
	int ai = 0;
	int bi = 0;

	while(ai < n && bi < k)
	{
		if(A[ai] < B[bi].first)
		{
			ai++;
		}
		else if(A[ai] >= B[bi].first && A[ai] <= B[bi].second)
		{
			result++;
			ai++;
		}
		else if(A[ai] > B[bi].second)
		{
			bi++;
		}
	}
	cout<<result<<endl;

}