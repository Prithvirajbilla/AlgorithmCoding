#include <bits/stdc++.h>
using namespace std;
int array[1000000];
int n;

int main()
{
	int n,k;
	cin>>n>>k;
	memset(array,0,sizeof(array));
	for (int i = 0; i < k; ++i)
	{
		int a,b;
		cin>>a>>b;
		array[a]+=1;
		array[b+1]+=-1;
	}
	for (int i = 1; i < n; ++i)
	{
		array[i] = array[i]+array[i-1];
	}
	sort(array,array+n);
	cout<<array[(n-1)/2]<<endl;
}