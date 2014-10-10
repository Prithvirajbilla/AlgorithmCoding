#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int K;
		cin>>K;
		long long m = K/2;
		long long n = K - m;
		cout<<m*n<<endl;
	}
	return 0;
}