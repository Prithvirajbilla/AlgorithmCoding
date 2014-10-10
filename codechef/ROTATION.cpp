#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,M;
	cin>>N>>M;
	int* array = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>array[i];
	}
	long long int pointer = 0;
	for (int i = 0; i < M; ++i)
	{
		char c; int d;
		cin>>c>>d;

		if(c == 'A')
		{
			pointer-=d;
			pointer %= N;
		}
		else if(c == 'C')
		{
			pointer+=d;
			pointer %= N;
		}
		else if(c == 'R')
		{
			long long int qq = (pointer+d-1);
			qq = qq%N;
			while(qq < 0)
			{
				qq+=N;
			}
			cout<<array[qq]<<endl;
		}
		while(pointer < 0)
		{
			pointer+=N;
		}
	}
}