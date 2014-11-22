#include <bits/stdc++.h>
using namespace std;
int len_bits(int n)
{
	int ans = 0;
	while(n > 0)
	{
		if(n&1)
		ans++;
		n/=2;
	}
	return ans;
}
int rev(int n)
{
	int ans = 0;
	int lent = 0;
	int tn = n;
	while(n > 0)
	{
		lent++;
		n/=2;
	}
	lent--;
	while(tn > 0)
	{
		if(tn&1)
		{
			ans |= (1<<(lent));
		}
		lent--;
		tn/=2;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int l = rev(n);
	if(l == r)
	{
		cout<<len_bits(l)<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}