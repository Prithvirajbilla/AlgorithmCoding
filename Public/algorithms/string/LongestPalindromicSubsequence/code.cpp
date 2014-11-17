#include <bits/stdc++.h>
using namespace std;
void print(int** array,int n)
{
	for(int i=0;i<n;i++)
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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int** array = new int*[n];
	for(int i=0;i<n;i++)
		array[i] = new int[n];

	fill(&(array[0][0]),&(array[0][0])+n*n,0);
	print(array,n);
	array[0][0]=1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=1;j<n;j++)
		{
			if(i ==j)
				array[i][j]=1;
			else if(i < j)
			{
				if(s[i]==s[j])
				 	array[i][j]=array[i+1][j-1]+2;
				else
					array[i][j]=max(array[i+1][j],array[i][j-1]);
			}
		}
	}
	cout<<*max_element(&(array[0][0]),&(array[0][0])+n*n)<<endl;
	print(array,n);
	return 0;
}
