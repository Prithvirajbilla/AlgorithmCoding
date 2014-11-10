#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void print(int k)
{
	if(k == 0)
	{
		cout<<"Airborne wins."<<endl;
	}
	else
	{
		cout<<"Pagfloyd wins."<<endl;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		print(k);
	}
	return 0;

}
