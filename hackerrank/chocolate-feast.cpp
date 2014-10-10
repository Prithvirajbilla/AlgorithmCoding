#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int N,C,M;
		cin>>N>>C>>M;
		int answer = 0;
		answer+=N/C;
		int K = N/C;
		while(K >= M)
		{
			answer+=(K/M);
			int l = K/M;
			K = K%M+l;
		}
		cout<<answer<<endl;
	}
	return 0;
}