#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin>>k;
		a.push_back(k);
	}
	sort(a.begin(),a.end());
	if(n == 0)
	{
		cout<<"YES"<<endl;
		cout<<1<<endl;
		cout<<1<<endl;
		cout<<3<<endl;
		cout<<3<<endl;
	}
	else if(n == 4)
	{
		float mn = a[0]+a[1]+a[2]+a[3];
		mn/=4;
		float mdn = a[1]+a[2];
		mdn/=2;
		float rs = a[3]-a[0];
		if(mn == mdn && mdn == rs)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	else if(n == 1)
	{
		cout<<"YES"<<endl;
		cout<<a[0]<<endl;
		cout<<3*a[0]<<endl;
		cout<<3*a[0]<<endl;
	}
	else if(n == 2)
	{
		if(a[1] == a[0])
		{
			cout<<"YES"<<endl;
			cout<<3*a[0]<<endl;
			cout<<3*a[0]<<endl;
		}
		else if((a[0]+a[1])%2 == 0 && (a[0]+a[1])/2 == (a[1]-a[0]))
		{
			cout<<"YES"<<endl;
			cout<<a[1]-a[0]<<endl;
			cout<<a[1]-a[0]<<endl;
		}
		else if(4*a[0]-a[1] > 0)
		{
			cout<<"YES"<<endl;
			cout<<4*a[0]-a[1]<<endl;
			cout<<3*a[0]<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	else if(n == 3)
	{
		if((a[0]+a[1])%4 == 0 && (3*(a[0]+a[1]))/4 == (a[2]))
		{
			cout<<"YES"<<endl;
			cout<<a[2]/3<<endl;
		}
		else if((3*(a[1]+a[2]))%4 == 0 && (3*(a[1]+a[2]))/4 == 3*a[0])
		{
			cout<<"YES"<<endl;
			cout<<3*a[0]<<endl;
		}
		else if(3*a[0] == a[2])
		{
			cout<<"YES"<<endl;
			cout<<4*a[0]-a[1]<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}