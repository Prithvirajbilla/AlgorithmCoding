#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > w(1001,vector<int>(1001));
vector<int> ct(1001);
int main()
{
	int t;
	cin>>t;
	set<int> check;
	for(int i=0; i<t;i++)
	{
		int k;
		cin>>k;
		ct[i] = k;
		for (int j = 0; j < k; ++j)
		{
			
			cin>>w[i][j];
			check.insert(w[i][j]);
		}
	}
	int n = check.size();
	vector<int> ans;
	int k =0;
	while(ans.size() < n)
	{
		for (int i = 0; i < t; ++i)
		{
			if(ct[i] == 0)
				continue;
			for (int j = 0; j < ct[i]; ++j)
			{
				
			}
		}
	}

	return 0;
}