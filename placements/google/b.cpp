#include <bits/stdc++.h>
using namespace std;
int cas = 1;
int n;
pair<int,int> ct[505];
int main()
{
	int T;
	cin>>T;
	for(int cas = 1; cas <= T; cas++)
	{
		cin>>n;
		memset(ct,0,sizeof(ct));
		for (int i = 0; i < n; ++i)
		{
			int a,b;
			cin>>a>>b;
			ct[i] = make_pair(a,b);
		}
		sort(ct,ct+n);
		int p;
		cin>>p;
		printf("Case #%d:",cas);
		for (int i = 0; i < p; ++i)
		{
			int k;
			cin>>k;
			int ans = 0;
			for (int j = 0; j < n; ++j)
			{
				if(k >= ct[j].first && k <= ct[j].second)
				{
					ans++;
				}
			}
			cout<<" "<<ans;
		}
		cout<<endl;
	}
}