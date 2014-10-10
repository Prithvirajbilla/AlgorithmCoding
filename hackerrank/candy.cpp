#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int N,K;
	cin>>N>>K;
	int* array = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>array[i];
	}
	sort(array,array+N);
	int min = 2147483647;
	for(int i=0; i <N-K;i++)
	{
		int r = array[i+K-1]-array[i];
		if(min > r)
		{
			min = r;
		}
	}
	cout<<min<<endl;
	return 0;
}