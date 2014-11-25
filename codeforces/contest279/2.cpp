#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
ll modulo(ll a,ll b,ll m)
{
	if(b == 0)
		return 1;
	else if(b%2 == 0)
	{
		ll temp = modulo(a,b/2,m);
		return (temp*temp)%m;
	}
	else 
	{
		ll temp = modulo(a,b/2,m);
		temp = (temp*temp)%m;
		return (temp*a)%m;
	}
}
int main()
{
	cin>>s;
	ll a,b;
	cin>>a>>b;
	ll left_sum = 0;
	ll right_sum = 0;
	bool h = true;
	int n = s.length();
	for (int i = 0; i < n; ++i)
	{
		right_sum*= 10;
		right_sum+=s[i]-'0';
		right_sum%= b;
	}
	for (int i = 0; i < n; ++i)
	{
		//check if the substr(0,i) substr(i,n) both are divisible by a and b
		
		left_sum *= 10;
		left_sum += (s[i]-'0');
		left_sum%= a;

		right_sum -= modulo(10,n-i-1,b)*(s[i]-'0');
		right_sum %= b;
		if(left_sum == 0 && right_sum == 0 && i+1 < n && s[i+1] != '0')
		{
			cout<<"YES"<<endl;
			for (int j = 0; j < n; ++j)
			{
				cout<<s[j];
				if(i == j)
					cout<<"\n";

			}
			cout<<endl;
			h = false;
			break;
		}
	}
	if(h)
		cout<<"NO"<<endl;

}