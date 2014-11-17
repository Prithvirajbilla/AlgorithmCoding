#include <bits/stdc++.h>
using namespace std;
vector<int> lrg,sml;
void solve(int m,int s)
{
	if(m == 0)
		return ;
	if(s>9)
	{
		lrg.push_back(9);
		sml.push_back(9);
		solve(m-1,s-9);
	}
	else if(s <= 9)
	{
		if(m == 1)
		{
			lrg.push_back(s);
			sml.push_back(s);
		}
		else if(s >=m)
		{
			lrg.push_back(s);
			for(int i=0; i<m-1;i++)
				lrg.push_back(0);
			sml.push_back(1);
			for (int i = 0; i < m-2; ++i)
			{
				sml.push_back(0);
			}
			sml.push_back(s-1);

		}
		else
		{
			lrg.push_back(s);
			for (int i = 0; i < m-1; ++i)
			{
				lrg.push_back(0);
			}
			sml.push_back(1);
			for (int i = 0; i < m-2; ++i)
			{
				sml.push_back(0);
			}
			sml.push_back(s-1);
		}
		return ;
	}
}
int main()
{
	int m,s;
	cin>>m>>s;
	if(m == 1 && s == 0)
	{
		cout<<0<<" "<<0<<endl;
		return 0;
	}
	if(s >m*9 || s == 0)
	{
		cout<<"-1 -1"<<endl;
		return 0;
	}
	solve(m,s);
	sort(sml.begin(),sml.end());
	sort(lrg.begin(),lrg.end(),greater<int>());
	int smzeros = 0;
	int ct = 0;
	vector<int> sd;
	for (int i = 0; i < sml.size(); ++i)
	{
		if(sml[i] == 0) smzeros++;
		else if(ct == 0)
		{	
			cout<<sml[i];
			ct++;
		}
		else
		{
			sd.push_back(sml[i]);
		}
	}
	for (int i = 0; i < smzeros; ++i)
	{
		cout<<0;
	}
	for (int i = 0; i < sd.size(); ++i)
	{
		cout<<sd[i];
	}
	cout<<" ";
	for (int i = 0; i < lrg.size(); ++i)
	{
		cout<<lrg[i];
	}
	cout<<endl;

}