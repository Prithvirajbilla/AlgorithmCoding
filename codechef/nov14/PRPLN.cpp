#include <bits/stdc++.h>
using namespace std;
string s;
bool is_pal(string a)
{
	for (int i = 0; i < a.length()/2; ++i)
	{
		if(a[i] != a[a.length()-1-i])
			return false;
	}
	return true;
}

bool can_be(int i,int j)
{
	if(i >= j)
	{
		return true;
	}
	if(s[i] == s[j])
	{
		return can_be(i+1,j-1);
	}
	if(s[i] != s[j])
	{
		string a(s);
		a.erase(i,1);
		string b(s);
		b.erase(j,1);
		if(is_pal(a) || is_pal(b))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>s;
		int n = s.length();
		if(can_be(0,n-1))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}