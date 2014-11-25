#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	if(s1.length() != s2.length())
	{
		cout<<0<<endl;
		return 0;
	}

	int target = 0;
	for (int i = 0; i < s1.length(); ++i)
	{
		if(s1[i] == '+') target++;
		else target--;
	}
	int now_position = 0;
	int unknwn = 0;
	for (int i = 0; i < s2.length(); ++i)
	{
		if(s2[i] == '+') now_position++;
		else if(s2[i] == '-') now_position--;
		else unknwn++;
	}
	double prob = 0.0;
	int ans = 0;
	for(int i = 0; i< (1<<unknwn);i++)
	{
		int k = i;
		int pr = 0;
		int ct = 0;

		while(k >= 0)
		{
			if(ct >= unknwn)
				break;
			if(k&1)
				pr++;
			else 
				pr--;
			k/=2;
			ct++;

		}
		if(pr+now_position == target)
			ans++;
	}
	prob = ans;
	prob /= (1<<unknwn);
	printf("%.9f\n",prob);

	return 0;
}