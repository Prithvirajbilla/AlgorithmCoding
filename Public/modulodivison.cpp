#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,power2;
	cin>>a>>power2;
	int result = a &(power2 - 1);
	cout<<result<<endl;
	return 0;
}