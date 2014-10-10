#include <bits/stdc++.h>
using namespace std;

bool detectOpposite(int a,int b)
{
	return (a ^ b)>>31;
}
int main()
{
	int a = -100,b = -1;
	if(detectOpposite(a,b))
	{
		cout<<"different"<<endl;
	}
	else
	{
		cout<<"not different"<<endl;
	}
}