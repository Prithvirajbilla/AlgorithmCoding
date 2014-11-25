#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int bal = 0;
		int max_bal = 0;
		for(int i=0; i < s.length();i++)
		{
			if(s[i] == '(') bal++;
			if(s[i] == ')') bal--;
			max_bal = max(max_bal,bal);
		}
		for(int i=0; i<max_bal; i++)
			cout<<"(";
		for (int i = 0; i < max_bal; ++i)
		{
			cout<<")";
		}
		cout<<endl;
	}
}