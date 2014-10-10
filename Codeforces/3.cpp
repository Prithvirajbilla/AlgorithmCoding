#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int m,n;
	cin>>m>>n;
	ll* array = new ll[m+1];
	array[1] = 1; 
	ll* sum = new ll[m+1];
	sum[1] = 1;
	for (int i = 2; i <= m; ++i)
	{
		array[i] = pow(i,n)-sum[i-1];
		sum[i]=array[i]+sum[i-1];
	}
/*	for (int i = 1; i <= m ; ++i)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	for (int i = 1; i <= m ; ++i)
	{
		cout<<sum[i]<<" ";
	}
	cout<<endl;
*/
	ll answer = 0;
	for (int i = 1; i <= m ; ++i)
		{
			answer+= i*array[i];
		}

	double aa = answer*1.0/pow(m,n) ;
	std::cout << std::fixed;
    std::cout << std::setprecision(12);
	cout<<aa<<endl;
	return 0;


}