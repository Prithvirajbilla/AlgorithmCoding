#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int k = n && !(n & (n-1));
	// 0 
	//if 0 false
	if(k)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	return 0;


}