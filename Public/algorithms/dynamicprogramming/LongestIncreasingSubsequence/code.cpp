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
	int m;
	cin>>m;
	int* input = new int[m];
	int* sorted_array = new int[m];
	for (int i = 0; i < m; ++i)
	{
		cin>>input[i];
		sorted_array[i] = input[i];
	}
	sort(sorted_array,sorted_array+m);
	int** array = new int*[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		array[i] = new int[m+1];
	}
	for (int i = 0; i < m+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			if(i == 0 || j == 0)
			{
				array[i][j] = 0;
			}
			else if(input[i-1] == sorted_array[j-1])
			{
				array[i][j] = array[i-1][j-1]+1;
			}
			else
			{
				array[i][j] = max(array[i][j-1],array[i-1][j]);
			}
		}
	}
	print(array,m+1,m+1);
}