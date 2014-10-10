#include <bits/stdc++.h>
using namespace std;
string s,t;
int a,b,k;
int m,n;
int arr[2][1000005];
int ind = 0;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		cin>>a>>b>>k;
		memset(arr, 0, sizeof(arr[0][0])*1000005*2);
		m = s.length();
		n = t.length();
		ind = 0;
		for (int j = 1; j <= n ; ++j)
		{
			arr[ind][j] = a*j;
		}
		for (int j = 1; j <= n; ++j)
		{
			int start = max(j-k,1);
			int end = min(j+k,n);
			ind++;
			for(int i=start; i<= end;i++)
			{
				if(s[i] == t[j])
				{
					arr[ind%2][j] = (j==1)?a*i:arr[(ind-1)%2][j-1];	
				}
				else
				{
					int one = arr[(ind-1)%2][j]+a;
					int two = (j == 1)?a*i:arr[(ind)%2][j-1]+a;
					int three = (j==1)?a*i:arr[(ind-1)%2][j-1]+b;
					arr[ind%2][j] = min(one,min(two,three));
				}
			}
		}
		if(arr[ind%2][n] > k)
		{
			cout<<-1<<endl;
		}
		else
		cout<<arr[ind%2][n]<<endl;
	}
}

		if(s.length() == 0)
		{
			if(t.length() <= k)
			{
				cout<<t.length()<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
			continue;
		}
		if(t.length() == 0)
		{
			if(s.length() <= k)
			{
				cout<<s.length()<<endl;
			}
			else
			{
				cout<<-1<<endl;
			}
			continue;
		}
