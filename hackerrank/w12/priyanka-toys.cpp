#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005] = {0};
int main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int cst= 0;
	int st = 0;
	while(st < n)
	{
		int wst = a[st];
		while(st < n && a[st] <= wst+4)
			st++;
		cst+=1;
	}
	cout<<cst<<endl;
}