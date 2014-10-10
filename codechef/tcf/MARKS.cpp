#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll array[5][101]={0};
ll num[5] = {0};
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char a;int m;
		cin>>a>>m;
		array[a-'A'][m]++;
		num[a-'A']++;
	}
	for (int i = 0; i < 5; ++i)
	{
		bool has = true;
		for (int j = 0; j <=100 ; ++j)
		{
			if(array[i][j] > num[i]*0.1)
			{
				cout<<j<<" ";
				has = false;
			}
		}
		if(has)
		{
			cout<<"Nothing Unusual";
		}
		cout<<endl;
	}
}