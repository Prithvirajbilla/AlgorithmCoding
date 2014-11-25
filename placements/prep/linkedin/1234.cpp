#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int f(vector<int> v,int prev)
{
	vector<int> vupd(v);
	v[prev]--;
	if(v[prev] >= 0)
	{
		return f(vupd,(prev+1)%4)+f(vupd,(prev+2)%4)+f(vupd,(prev+3)%4);
	}
	else
		return 1;
}

int main()
{
	std::vector<int> v(4);
	cin>>v[0]>>v[1]>>v[2]>>v[3];
	cout<<f(v,0)<<endl;
	



}