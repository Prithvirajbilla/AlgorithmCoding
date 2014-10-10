#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int n;
	cin>>n;
	ll* array = new ll[n];
	ll* diff = new ll[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	sort(array,array+n);
	set<int> d_set;
	for (int i = 1; i < n; ++i)
	{
		diff[i] = array[i] - array[i-1];
		d_set.insert(diff[i]);
	}
	if(d_set.size() > 2)
	{
		cout<<0<<endl;
		return 0;
	}

	if(n == 1)
	{
		cout<<-1<<endl;
		return 0;
	}

	if(n == 2)
	{
		//special case
		int no =0;
		int cdf = array[1] - array[0];
		set<int> ans;
		ans.insert(array[0] - cdf);
		ans.insert(array[1] + cdf);
		no+=2;
		if(cdf == 0)
		{
			cout<<1<<endl;
			cout<<array[1]<<endl;
			return 0;
		}

		if(cdf%2 == 0)
		{
			ans.insert(array[0]+cdf/2);
			no++;
		}
		cout<<no<<endl;
		for (set<int>::iterator it=ans.begin();it != ans.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
		return 0;
	}

	if(d_set.size() == 1)
	{
		int no =0;
		int cdf = array[1] - array[0];
		if(cdf == 0)
		{
			cout<<1<<endl;
			cout<<array[1]<<endl;
			return 0;
		}
		else
		{
			cout<<2<<endl;
			cout<<array[0]-cdf<<" "<<array[n-1]+cdf<<endl;
			return 0;
		}
	}
	else
	{
		set<int>::iterator it = d_set.begin();
		int cdf = *it;
		set<int>:: reverse_iterator it1 = d_set.rbegin();
		int cdf2 = *it1;
		if(cdf2 == cdf*2)
		{
			int j;
			int next = 0;
			for(j=1;j < n;j++)
			{
				if(array[j-1]+cdf == array[j])
				{
					continue;
				}
				else
				{
					next = array[j-1]+cdf;
					break;
				}
			}
			for(int k =j; k<n-1;k++)
			{
				if(array[k]+cdf2== array[k+1])
				{
					cout<<0<<endl;
					return 0;
				}
			}
			cout<<1<<endl;
			cout<<next<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}


}