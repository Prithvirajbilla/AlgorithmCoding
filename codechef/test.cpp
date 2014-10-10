#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n =91;
	int* array = new int[n];
	for (int i = 1; i <= n; ++i)
	{
		double kkk = n;
		kkk /= i;
		// cout<<i<<" : "<< n/i <<" : "<<kkk<<" , ";
		array[i-1] = n/i ;
	}
	// cout<<endl;
	for (int i = 0; i < n;)
	{
	
		int count = 0;
		int a = array[i];
		while(a == array[i] && i < n)
		{
			i++;
			count++;
		}
		cout<<a<<" "<<count<<endl;
	}
}