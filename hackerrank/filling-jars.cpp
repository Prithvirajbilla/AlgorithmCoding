#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int N,M;
	cin>>N>>M;
	long long int ans = 0;
	for (int i = 0; i < M; ++i)
	{
		long long int a,b,k;
		cin>>a>>b>>k;
		ans+=((b-a+1)*k);
	}
	cout<<ans/N<<endl;
	return 0;
}
