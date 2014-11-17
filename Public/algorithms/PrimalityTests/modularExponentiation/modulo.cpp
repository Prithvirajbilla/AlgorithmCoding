#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll modulo(int a,int b,int c)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b%2 == 0)
	{
		ll temp = modulo(a,b/2,c);
		return (temp*temp)%c;
	}
	else
	{
		ll temp = modulo(a,b/2,c);
		return (a*(temp*temp)%c)%c;
	}
}
int main(int argc, char const *argv[])
{
	int a,b,c;
	cout<<modulo(a,b,c)<<endl;
	return 0;
}