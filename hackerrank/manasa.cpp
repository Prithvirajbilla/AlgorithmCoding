#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int N,A,B;
		cin>>N>>A>>B;
		set<long long> a;
		a.insert(0);
		for (int j = 1; j < N; ++j)
		{
			set<long long> b;
			set<long long> :: iterator it;
			for (it = a.begin();it!=a.end();it++)
			{
				long long k = *it;
				b.insert(k+A);
				b.insert(k+B);
			}
			a=b;
		}
		for (set<long long> :: iterator it = a.begin(); it != a.end() ; ++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}