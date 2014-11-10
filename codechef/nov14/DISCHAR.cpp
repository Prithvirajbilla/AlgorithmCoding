#include <bits/stdc++.h>
using namespace std;
int a[26];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.length();
		memset(a,0,sizeof(a));
		for (int i = 0; i < n; ++i)
		{
			a[s[i]-'a']++;
		}
		int ans = 0;
		for(int i =0; i<26; i++)
		{
			if(a[i] > 0)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}