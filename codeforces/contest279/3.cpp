#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll a1,b1,a2,b2;
int get_res(ll a,int m)
{
	int ans = 0;
	while(a%m == 0)
	{
		a /=m;
		ans++;
	}
	return ans;
}

int main()
{
	cin>>a1>>b1>>a2>>b2;
	vector<int> l,m;

	l.push_back(get_res(a1,2));
	l.push_back(get_res(a1,3));
	l.push_back(get_res(b1,2));
	l.push_back(get_res(b1,3));

	m.push_back(get_res(a2,2));
	m.push_back(get_res(a2,3));
	m.push_back(get_res(b2,2));
	m.push_back(get_res(b2,3));

	int t1 = min(l[0]+l[2],m[0]+m[2]);
	int t2 = min(l[1]+l[3],m[1]+m[3]);

	ll a11 = a1;
	a11 /= pow(2,l[0])*pow(3,l[1]);
	ll b11 = b1;
	b11 /= pow(2,l[2])*pow(3,l[3]);

	ll a21 = a2;
	a21 /= pow(2,m[0])*pow(3,m[1]);
	ll b21 = b2;
	b21 /= pow(2,m[2])*pow(3,m[3]);
	if(a21*b21 != a11*b11)
	{
		cout<<-1<<endl;
		return 0;
	}
	
	cout<<abs(l[0]+l[2]-m[0]-m[2])+abs(l[1]+l[3]-m[1]-m[3])<<endl;
	if(l[0]+l[2] > m[0]+m[2])
	{
		int req = abs(l[0]+l[2]-m[0]-m[2]);
		int ch = 0;
		while(ch < req && a1%2 == 0)
		{
			a1/=2;
			ch++;
		}
		while(ch < req && b1%2 == 0)
		{
			b1/=2;
			ch++;
		}
	}
	else
	{
		int req = abs(l[0]+l[2]-m[0]-m[2]);
		int ch = 0;
		while(ch < req && a2%2 == 0)
		{
			a2/=2;
			ch++;
		}
		while(ch < req && b2%2 == 0)
		{
			b2/=2;
			ch++;
		}
	}

	if(l[1]+l[3] > m[1]+m[3])
	{
		int req = abs(l[1]+l[3]-m[1]-m[3]);
		int ch = 0;
		while(ch < req && a1%3 == 0)
		{
			a1/=3;
			ch++;
		}
		while(ch < req && b1%3 == 0)
		{
			b1/=3;
			ch++;
		}
	}
	else
	{
		int req = abs(l[1]+l[3]-m[1]-m[3]);
		int ch = 0;
		while(ch < req && a2%3 == 0)
		{
			a2/=3;
			ch++;
		}
		while(ch < req && b2%3 == 0)
		{
			b2/=3;
			ch++;
		}
	}
	cout<<a1<<" "<<b1<<endl;
	cout<<a2<<" "<<b2<<endl;





}