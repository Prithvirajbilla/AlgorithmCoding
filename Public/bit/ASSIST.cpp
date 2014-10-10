#include <bits/stdc++.h>
using namespace std;
int main()
{
	 bool array[50000];
	 fill(array,array+50000,true);
	 vector<int> primes;
	 for (int i = 2; i < 50000; ++i)
	 {
	 	if(array[i] == true)
	 	{
	 		primes.push_back(i);
	 		array[i] = false;
	 		int count = 0;
	 		for(int j = i;j < 50000;j++)
	 		{
	 			if(array[j] == true)
	 			{
	 				count++;
	 			}
	 			if(count == i)
	 			{
	 				array[j] = false;
	 				count = 0;
	 			}
	 		}
	 	}
	 	else
	 		continue;
	 }
	int now;
	cin>>now;
	while(now != 0)
	{
		cout<<primes[now-1]<<endl;
		cin>>now;
	}
	return 0;
}