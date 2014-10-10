#include <bits/stdc++.h>
using namespace std;
#define cond(c) c == '+' || c == '-' || c == '*' || c == '/' || c== '^'

// a*(b+c) => abc+*
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
int main()
{
	string s;
	cin>>s;
	stack<char> inf_s;
	int i =0;
	while(i < s.length())
	{
		if(cond(s[i]))
		{
			//the top in the stack has higher precendence than s[i], so pop them
			while(!inf_s.empty() && Prec(inf_s.top()) > Prec(s[i]))
			{
				cout<<inf_s.top();
				inf_s.pop();
			}
			inf_s.push(s[i]);
		}
		else if(s[i] == '(')
		{
			inf_s.push('(');
			i++;
			continue;
		}
		else if(s[i] == ')')
		{
			while(!inf_s.empty() && inf_s.top() != '(')
			{
				cout<<inf_s.top();
				inf_s.pop();
			}
			if(!inf_s.empty() && inf_s.top() == '(')
			{
				inf_s.pop();
			}
		}
		else
		{
			cout<<s[i];
		}
		i++;
	}
	cout<<endl;
	return 0;
}