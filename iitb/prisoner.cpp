#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int n,t,c;
	cin>>n>>t>>c;
	ll* array = new ll[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	int number = 0;
	vector<int> count;
	for (int i = 0; i < n; ++i)
	{
		if(array[i] > t)
		{
			count.push_back(number);
			number = 0;
		}
		else
			number++;
	}
	count.push_back(number);
	ll answer = 0;
	for(int i=0; i< count.size();i++)
	{
		if(count[i] >= c)
		{
			answer += count[i] - c + 1;
		}
	}
	cout<<answer<<endl;
	return 0;
}