#include <bits/stdc++.h>
using namespace std;
int b[105][105] = {0};
int a[105][105] = {0};
int m,n;
int main()
{
	cin>>m>>n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>b[i][j];
		}
	}

	bool is = true;
	int r=0,c=0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(b[i][j] == 1)
			{
				bool ans1 = true,ans2 = true;
				for(int k=0; k<m;k++)
				{
					if(b[k][j] != 1)
					{
						ans1 = false;
						break;
					}
				}
				for(int k=0; k<n;k++)
				{
					if(b[i][k] != 1)
					{
						ans2 = false;
						break;
					}
				}
				if(ans1 == false && ans2 == false)
				{
					is = false;
					break;
				}
				else if(ans1 == true && ans2 == true)
				{
					a[i][j] = 1;
				}

				if(j == 0 && ans2 == true )
				{
					r++;
				}
				if(i == 0  && ans1 == true)
				{
					c++;
				}
			}
		}
		if(!is)
			break;
	}
	// cout<<r<<" "<<c<<endl;
	if(r > 0 && c == 0)
	{
		is = false;
	}
	if(c >0 && r== 0)
	{
		is = false;
	}
	if(is)
	{
		cout<<"YES"<<endl;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}