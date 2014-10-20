#include <bits/stdc++.h>
using namespace std;
int k,l,m;
int array[1000005];
void fill(int n)
{
	memset(array,0,sizeof(array));
	array[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		//check if atleast one is 0
		if(i-1>= 0 && !array[i-1])
		{
			array[i] = 1;
		}
		if(i-k >= 0 && !array[i-k])
		{ 
			array[i] = 1;
		}
		if(i-l >= 0 && !array[i-l])
		{
			array[i] = 1;
		}

		if(array[i] != 1)
		{
			array[i] = 0;
		}
	}
	// for (int i = 0; i <= n; ++i)
	// {
	// 	cout<<array[i]<<" ";
	// }
	// cout<<endl;

}
int main()
{
	cin>>k>>l>>m;
	int all[51] = {0};
	for (int i = 0; i < m; ++i)
	{
		cin>>all[i];
	}
	fill(*max_element(all,all+m));
	for (int i = 0; i < m; ++i)
	{
		if(array[all[i]])
		{
			cout<<"A";
		}
		else
		{
			cout<<"B";
		}
	}
	cout<<endl;
}