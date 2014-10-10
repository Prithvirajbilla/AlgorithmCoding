#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool array[1000000]= {true};
vector<int> primes;
void fill_array()
{
	fill(array,array+1000000,true);
	for(int i=2;i <1000000;i++)
	{
		if(array[i])
		{
			int k = 2*i;
			while( k < 1000000)
			{
				array[k] = false;
				k+=i;
			}
		}
	}
	//collect;
	for (int i = 2; i < 1000000; ++i)
	{
		if(array[i] == true)
			primes.push_back(i);
	}

}
int main()
{
	//preprocess
	fill_array();
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		ll t;
		cin>>t;
		bool no = false;
		int no_p = 0;
		int t1= t;
		for (int j = 0; j < primes.size(); j++)
		{
			ll c = primes[j];
			c *= c;
			if(c == t)
			{
				no = true;
				break;
			}
			while(t1%primes[j] == 0)
			{
				no_p++;
				t1 /=primes[j];
			}
			if(no_p > 2)
			{
				break;
			}

		}
		if(no)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}