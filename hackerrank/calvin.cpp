#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,T;
	cin>>N>>T;
	int* array = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>array[i];
	}
	for (int i = 0; i < T; ++i)
	{
		int m,n;
		cin>>m>>n;
		int min =4;
		for (int j = m; j <= n ; ++j)
		{
			if(array[j] < min)
			{
				min = array[j];
			}
		}
		cout<<min<<endl;
	}

}