#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll packers[101];
int m;
ll get_result(ll max,int i,int n,int m1,double pb)
{
	int start = i;
	ll sum = 0;
	if(m1 == m-1)
	{
		while(i < n)
		{
			sum+=packers[i];
			i++;
		}
		if(max < sum)
			return sum;
		else
			return max;
	}
	while(i < n)
	{
		sum+=packers[i];
		if(sum > pb)
		{
			ll sum1 = sum;
			ll sum2 = sum - packers[i];
			ll max1 = max,max2 = max;
			if(sum1 > max1)
				max1 = sum1;
			if(sum2 > max2)
				max2 = sum2;
			if(start == i)
				return get_result(max1,i+1,n,m1+1,pb);
			else
				return min(get_result(max1,i+1,n,m1+1,pb),get_result(max2,i,n,m1+1,pb));
				
		}
/*		cout<<i<<endl;
*/		i++;
	}
	if(sum > max)
		max = sum;
	
	return max;

}
int main()
{
	int p;
	cin>>m>>p;
	ll sum = 0;
	for (int i = 0; i < p; ++i)
	{
		cin>>packers[i];
		sum += packers[i];
	}
	double pbm = sum/m;
	cout<<get_result(0,0,p,0,pbm)<<endl;
	return 0;

}