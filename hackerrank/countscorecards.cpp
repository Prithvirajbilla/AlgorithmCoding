#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[801][802];

void populate()
{
	a[0][0] = 1;
	for (int i = 1; i < 801; i++)
	{
		a[i][0] = 1;
		for (int j = 1; j <=i ; j++)
		{
			if(i == j)
				a[i][j] = 1;
			else
				a[i][j] = (a[i-1][j]+a[i-1][j-1])%MOD;
		}
	}
/*	for (int i = 0; i < 801; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
*/}
int main()
{
	int T;
	cin>>T;
	populate();
	for (int i = 0; i < T; i++)
	{
		int num;
		cin>>num;
		int k = 0;
		int sum = 0;
		int * array = new int[num];
		for (int j = 0; j < num; j++)
		{
			cin>>array[j];
			if(array[j] == -1)
			{
				k++;
			}
			else
			{
				sum+=array[j];
			}
		}
		int n = (num*(num-1))/2;
		if(k == 0)
		{
			if(sum == n)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
			continue;
		}

		n-=sum;
		/*cout<<a[n+k-1][k-1]<<endl;*/
		int C = num-1;
		long long ans = 0;
		for (int r = 0; r <=k ; r++)
		{
			long long ak= 1*pow(-1,r);
			ak*=a[k][r];
			ak%=MOD;
			if(n-(r*C)+k-r-1 < 0)
			{
				continue;
			}
			cout<<n-(r*C)+k-r-1<<" "<<k-1<<endl;
			ak*=a[n-(r*C)+k-r-1][k-1];
			ak%=MOD;
			ans+=ak;
			cout<<ak<<endl;
		}
		cout<<ans<<endl;
	}
}