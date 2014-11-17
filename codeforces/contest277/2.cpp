#include <bits/stdc++.h>
using namespace std;
int n,p;
string s;

int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}
int main()
{
	cin>>n>>p;
	cin>>s;
	int ans = 0;
	p--;
	int a1,a2,b1,b2;
	a1 = a2 = 100005;
	b1 = b2 = -1;
	for (int i = 0; i < s.length()/2; ++i)
	{
		if(s[i] != s[n-i-1])
		{
			ans+=min(mod(s[n-i-1]-s[i],26),mod(s[i]-s[n-i-1],26));
			a1 = min(i,a1);
			a2 = min(n-i-1,a2);
			b1 = max(i,b1);
			b2 = max(n-i-1,b2);
		}
	}
	if(ans == 0)
	{
		cout<<0<<endl;
		return 0;
	}

	if(p >= b1 && p <= a2)
	{
		ans+=min(abs(b2-p),abs(p-a1));
	}
	else if(p >= a1 && p<=b1)
	{
		ans+=min(abs(p-a1),abs(p-b1))+(b1-a1);
	}
	else if(p >= a2 && p<= b2)
	{
		ans+=min(abs(p-a2),abs(p-b2))+(b2-a2);
	}
	else if( p < a1)
	{
		ans+=min(b1-p,mod(p-a2,n));
	}
	else if(p > b2)
	{
		ans+=min(p-a2,mod(b1-p,n));
	}
	cout<<ans<<endl;
	return 0;
}