#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int main()
{
	int t;
	cin>>t;
	int cs;
	for(cs =1;cs <= t; cs++)
	{
		int n;
		string a;
		cin>>n>>a;
		memset(arr,0,sizeof(arr[0][0])*1000*1000);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>arr[i][j];
			}
		}
		if(a.compare("left") == 0)
		{
			for (int i = 0; i < n; ++i)
			{
				queue<int> a;
				for (int j = 0; j < n; ++j)
				{
					if(arr[i][j] != 0)
						a.push(arr[i][j]);
				}
				int current_pointer = 0;
				while(!a.empty())
				{
					int t = a.front();a.pop();
					if(a.empty())
					{
						arr[i][current_pointer] = t;
						current_pointer++;
						break;
					}
					if(a.front() == t)
					{
						arr[i][current_pointer] = 2*t;
						current_pointer++;
						a.pop();
					}
					else if(a.front() != t)
					{
						arr[i][current_pointer] = t;
						current_pointer++;
					}
				}
				for (int j = current_pointer; j < n; ++j)
				{
					arr[i][j] = 0;
				}
			}
		}
		else if(a.compare("right") == 0)
		{
			for (int i =0; i < n; i++)
			{
				queue<int> a;
				for (int j = n-1; j >=0 ; j--)
				{
					if(arr[i][j] != 0)
						a.push(arr[i][j]);
				}
				int current_pointer = n-1;
				while(!a.empty())
				{
					int t = a.front();a.pop();
					if(a.empty())
					{
						arr[i][current_pointer] = t;
						current_pointer--;
						break;
					}
					if(a.front() == t)
					{
						arr[i][current_pointer] = 2*t;
						current_pointer--;
						a.pop();
					}
					else if(a.front() != t)
					{
						arr[i][current_pointer] = t;
						current_pointer--;
					}
				}
				for (int j = current_pointer; j >= 0; j--)
				{
					arr[i][j] = 0;
				}
			}

		}
		else if(a.compare("up") == 0)
		{
			for (int i = 0; i < n; i++)
			{
				queue<int> a;
				for (int j = 0; j < n; ++j)
				{
					if(arr[j][i] != 0)
					a.push(arr[j][i]);
				}
				int current_pointer= 0;
				while(!a.empty())
				{
					int t = a.front();a.pop();
					if(a.empty())
					{
						arr[current_pointer][i] = t;
						current_pointer++;
						break;
					}
					if(a.front() == t)
					{
						arr[current_pointer][i] = 2*t;
						current_pointer++;
						a.pop();
					}
					else if(a.front() != t)
					{
						arr[current_pointer][i] = t;
						current_pointer++;
					}
				}
				for (int j = current_pointer; j < n; ++j)
				{
					arr[j][i] = 0;
				}
			}
		}
		else if(a.compare("down") == 0)
		{
			for (int i = 0; i < n; i++)
			{
				queue<int> a;
				for (int j = n-1; j >= 0; --j)
				{
					if(arr[j][i] != 0)
					a.push(arr[j][i]);
				}
				int current_pointer= n-1;
				while(!a.empty())
				{
					int t = a.front();a.pop();
					if(a.empty())
					{
						arr[current_pointer][i] = t;
						current_pointer--;
						break;
					}
					if(a.front() == t)
					{
						arr[current_pointer][i] = 2*t;
						current_pointer--;
						a.pop();
					}
					else if(a.front() != t)
					{
						arr[current_pointer][i] = t;
						current_pointer--;
					}
				}
				for (int j = current_pointer; j >= 0 ; j--)
				{
					arr[j][i] = 0;
				}
			}
		}
		cout<<"Case #"<<cs<<":"<<endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}