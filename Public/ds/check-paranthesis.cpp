#include <bits/stdc++.h>
using namespace std;
#define cond(c) c == '[' || c == '{' || c=='('
//'[' .'{','('
int main()
{
	string s;
	stack<int> check;
	cin>>s;
	check.push(s[0]);
	int i = 1;
	while(i <s.length())
	{
		if(cond(s[i]))
		{
			check.push(s[i]);
		}
		else
		{
			if(check.top() == '[' && s[i] == ']')
			{
				check.pop();
			}
			if(check.top() == '{' && s[i] == '}')
			{
				check.pop();
			}
			if(check.top() == '(' && s[i] == ')')
			{
				check.pop();
			}
			else
			{
				cout<<"Not Possible"<<endl;
				return -1;
			}
		}
		i++;
	}
	if(check.empty())
		cout<<"Possible"<<endl;
	else
		cout<<"Not Possible"<<endl;

	return 0;
}