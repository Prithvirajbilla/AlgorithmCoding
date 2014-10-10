#include <bits/stdc++.h>
using namespace std;
int array[100005];
pair<int,int> values[200010];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(array,0,sizeof(array));
		memset(values,0,sizeof(values));
		int n;
		cin>>n;
		int m;
		cin>>m;
		for (int i = 1; i <=n ; ++i)
		{
			cin>>array[i];
		}
		int en = 0;
		for (int i = 1; i <= m ; ++i)
		{
			int a,b;
			cin>>a>>b;
			values[++en] = make_pair(a,1);
			values[++en] = make_pair(b+1,-1);
		}
		sort(values+1,values+en+1);
		int balance = 0;
					int lft;
		for(int i=1; i<= en;i++)
		{
			balance +=values[i].second;
			if (balance == 1 && values[i].second == 1) lft =  values[i].first;
			if(balance == 0) sort(array+lft,array+values[i].first);
		}
		bool ok = true;
		for (int i = 1; i <= n ; ++i)
		{
			if(array[i] != i) ok = false;
		}
		if(ok)
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
	}
}