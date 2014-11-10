#include <bits/stdc++.h>
using namespace std;
int dp[300][4][4] = {0};
int num = 0;
int orig[4][4] = {0};
vector<vector<int> > all_ans;
bool is_sudoku(int arr[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		set<int> check1,check2;
		for (int j = 0; j < 4; ++j)
		{
			check1.insert(arr[i][j]);
			check2.insert(arr[j][i]);
		}
		if(check1.size() < 4)
			return false;
		if(check2.size() < 4)
			return false;
	}
	set<int> check1,check2;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			check1.insert(arr[i][j]);
			check2.insert(arr[j][i]);
		}
	}
	if(check1.size() < 4)
		return false;
	if(check2.size() < 4)
		return false;
	check1.clear();check2.clear();
	for (int i = 2; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			check1.insert(arr[i][j]);
			check2.insert(arr[j][i]);
		}
	}
	if(check1.size() < 4)
		return false;
	if(check2.size() < 4)
		return false;
	check1.clear();check2.clear();
	return true;
}
void enr()
{
	vector<int>marr;
	for (int i = 1; i <=4 ; ++i)
		marr.push_back(i);
	int count = 0 ;
	for (int i = 0; i < 24; ++i)
	{
		all_ans.push_back(marr);
		next_permutation(marr.begin(),marr.end());
	}
	for (int i = 0; i < 24; ++i)
	{
		for (int j = 0; j < 24; ++j)
		{
			for (int k = 0; k < 24; ++k)
			{
				for (int l = 0; l < 24; ++l)
				{
					int a[4][4];
					a[0][0] = all_ans[i][0];a[0][1] = all_ans[i][1];
					a[0][2] = all_ans[i][2];a[0][3] = all_ans[i][3];
					a[1][0] = all_ans[j][0];a[1][1] = all_ans[j][1];
					a[1][2] = all_ans[j][2];a[1][3] = all_ans[j][3];
					a[2][0] = all_ans[k][0];a[2][1] = all_ans[k][1];
					a[2][2] = all_ans[k][2];a[2][3] = all_ans[k][3];
					a[3][0] = all_ans[l][0];a[3][1] = all_ans[l][1];
					a[3][2] = all_ans[l][2];a[3][3] = all_ans[l][3];
					if(is_sudoku(a))
					{
						for (int h = 0; h < 4; ++h)
						{
							for (int p = 0; p < 4; ++p)
							{
								dp[num][h][p] = a[h][p];
							}
						}
						num++;
					}
				}
			}
		}
	}
}
int main()
{
	enr();
	int t;
	cin>>t;
	while(t--)
	{
		memset(orig,0,sizeof(orig[0][0])*4*4);
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				cin>>orig[i][j];
			}
		}
		int mi = 1000000;
		for (int i = 0; i < 288; ++i)
		{
			int var = 0;
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					int d = dp[i][j][k] - orig[j][k];
					var += abs(d)*abs(d);
				}
			}
			mi = min(var,mi);
		}
		cout<<mi<<endl;
	}

}