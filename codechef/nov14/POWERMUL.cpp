#include <bits/stdc++.h>
using namespace std;
long double a[2][2] = {0};
long double b[2][2] = {0};
long double mula[2][2] = {0};
long double temp[2][2] = {0};
long double tp[2] = {0.0};
long double final_ans = 0.0;
string s;
int t,n,k;
string gw;
void find_exp()
{
	int tk = k;
	while(tk)
	{
		if(tk&1)
		{
			memset(temp,0,sizeof temp);
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					for (int p = 0; p < 2; ++p)
					{
						temp[i][j] = temp[i][j]+mula[i][p]*b[p][j];
					}
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					mula[i][j] = temp[i][j];
				}
			}
		}

		memset(temp,0,sizeof temp);
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int p = 0; p < 2; ++p)
				{
					temp[i][j] = temp[i][j]+b[i][p]*b[p][j];
				}
			}
		}

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				b[i][j] = temp[i][j];
			}
		}
		tk /= 2;
	}
}

int main()
{
	cin>>k;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin>>a[i][j];
			mula[i][j] = (i == j)?1:0;
			b[i][j] = a[i][j];
		}
	}
	find_exp();
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout<<mula[i][j]<<" ";
		}
		cout<<endl;
	}


}
