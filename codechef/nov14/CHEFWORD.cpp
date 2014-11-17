#include <bits/stdc++.h>
using namespace std;
double a[26][26] = {0};
double b[26][26] = {0};
double mula[26][26] = {0};
double temp[26][26] = {0};
double tp[26] = {0.0};
double final_ans = 0.0;
set<string> asd;
string s;
int t,n,k;
void find_exp()
{
	int tk = k-2;
	while(tk)
	{
		if(tk&1)
		{
			memset(temp,0,sizeof temp);
			for (int i = 0; i < 26; ++i)
			{
				for (int j = 0; j < 26; ++j)
				{
					for (int p = 0; p < 26; ++p)
					{
						temp[i][j] = temp[i][j]+mula[i][p]*b[p][j];
					}
				}
			}
			for (int i = 0; i < 26; ++i)
			{
				for (int j = 0; j < 26; ++j)
				{
					mula[i][j] = temp[i][j];
				}
			}
		}

		memset(temp,0,sizeof temp);
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				for (int p = 0; p < 26; ++p)
				{
					temp[i][j] = temp[i][j]+b[i][p]*b[p][j];
				}
			}
		}

		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				b[i][j] = temp[i][j];
			}
		}
		tk /= 2;
	}
	// for (int i = 0; i < 26; ++i)
	// {
	// 	for (int j = 0; j < 26; ++j)
	// 	{
	// 		cout<<mula[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
}

void  solve()
{
	for(set<string>::iterator it = asd.begin();it!=asd.end();it++)
	{
		string gw = *it;
		double ans = 1.0;
		if(k == 1)
		{
			for (int i = 0; i < s.length(); ++i)
			{
				ans*=a[s[i]-'a'][gw[i]-'a'];
				// cout<<a[s[i]-'a'][gw[i]-'a']<<" ";
			}
			// cout<<endl;
		}
		else
		{
			for (int i = 0; i < s.length(); ++i)
			{
				double ans1 = 0.0;
				memset(tp,0,sizeof tp);
				for (int j = 0; j < 26; ++j)
				{
					for (int p = 0; p < 26 ; ++p)
					{
						tp[j] += mula[j][p]*a[p][gw[i]-'a'];
					}
				}
				for (int j = 0; j < 26; ++j)
				{
					ans1+=a[s[i]-'a'][j]*tp[j];
					// cout<<a[s[i]-'a'][j]*tp[j]<<" ";
				}
				// cout<<" = "<<ans1<<endl;
				ans*=ans1;
			}
		}
		final_ans+=ans;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(mula,0,sizeof mula);
		memset(temp,0,sizeof temp);
		final_ans = 0.0;
		asd.clear();

		cin>>n>>k;
		cin>>s;

		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				cin>>a[i][j];
				// a[i][j]*=10;
				b[i][j] = a[i][j];
				mula[i][j] = (i == j)?1:0;
			}
		}

		if(k >= 2)
			find_exp();

		
		for (int i = 0; i < n; ++i)
		{
			string gw;
			cin>>gw;
			if(gw.length() != s.length())
			{
				// cout<<0<<endl;
				continue;
			}
			asd.insert(gw);
		}
		solve();
		printf("%.6f\n",final_ans);
	}
}