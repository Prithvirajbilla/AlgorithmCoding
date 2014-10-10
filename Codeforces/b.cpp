#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n;
	cin>>n;
	ll* array = new ll[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	sort(array,array+n);
	int max_diff = array[n-1]-array[0];
	ll a = 0;
	for (int i = 0; i < n; ++i)
	{
		if(array[i] != array[0])
		{
			break;
		}
		else
			a++;
	}
	ll b = 0;
	for (int i = n-1; i >=0 ; i--)
	{
		if(array[i] != array[n-1])
		{
			break;
		}
		else
			b++;
	}
	ll product = 0;
	if(max_diff == 0)
	{
		product = (n*(n-1))/2;
	}
	else
	{
		product = a*b;
	}
	cout<<max_diff<<" "<<product<<endl;
	return 0;
}