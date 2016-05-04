#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll D;
string s;

bool check(string s)
{
	if(s.length() == 1)
		return false;
	
	if(s.length()%2 == 0)
	{
		int k = s.length()/2;
		for(int i=0; i < s.length()/2;i++)
		{
			if(s[i] != s[i+k])
				return false;
		}
		return true;
	}
	else
	{
		int i=0,j=s.length()/2+1,match=0,nomatch=0;
		int match1=0,nomatch1 = 0;
		while(i <= s.length()/2 && j < s.length())
		{
			// cout<<s[i]<<" "<<s[j]<<endl;
			if(s[i] == s[j]){
				match++;
				i++;
				j++;
			}
			else{
				i++;
				nomatch++;
			}
		}
		j = s.length()/2;i=0;
		while(j < s.length())
		{
			// cout<<s[i]<<" "<<s[j]<<endl;
			if(s[i] == s[j])
			{
				match1++;
				j++;
				i++;
			}
			else
			{
				j++;
			}
		}
		if(match == s.length()/2 || match1 == s.length()/2)
			return true;
		else
			return false;
	}
}


int main(int argc, char const *argv[])
{
	cin>>D;
	for (int i = 0; i < D; ++i)
	{
		cin>>s;
		// cout<<s<<endl;
		if(check(s))
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