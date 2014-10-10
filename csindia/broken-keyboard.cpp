#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int b[26]={0},w[26]={0};
		string bs,ws;
		cin>>bs;
		for (int i = 0; i < bs.length(); ++i)
			b[bs[i]-'a']++;

		cin>>ws;
		int count = 0;
		for (int i = 0; i < ws.length(); ++i)
		{
			if(w[ws[i]-'a'] == 0 && b[ws[i]-'a'] != 0)
			{
				count++;
				w[ws[i]-'a']++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}