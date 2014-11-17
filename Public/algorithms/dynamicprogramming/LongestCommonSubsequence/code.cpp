#include <bits/stdc++.h>
using namespace std;
void print(int** array,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	string x,y;
	cin>>x>>y;
	int m = x.length();
	int n = y.length();
	int** array = new int*[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		array[i] = new int[n+1];
	}
	for (int i = 0; i < m+1 ; i++)
	{
		for(int j=0; j < n+1;j++)
		{
			if(i == 0 || j == 0)
			{
				array[i][j] = 0;
			}
			else if(x[i-1] == y[j-1])
			{
				array[i][j] = array[i-1][j-1]+1;
			}
			else
			{
				array[i][j] = max(array[i-1][j],array[i][j-1]);
			}
		}
	}
	print(array,m+1,n+1);
	return 0;
}