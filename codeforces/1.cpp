#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back

int main()
{
	int n;
	cin>>n;
	char** array = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = new char[n];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			array[i][j] = '*';
		}
	}
	int k = n/2;
	int a = k;
	for (int i = 0; i < n; ++i)
	{		
			for (int j = a; j < n-a; ++j)
			{
				array[i][j] = 'D';
			}
			if(i < k)
			{
				a--;
			}
			else
			{
				a++;
			}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<array[i][j];
		}
		cout<<"\n";
	}
}