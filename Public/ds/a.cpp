#include <bits/stdc++.h>
using namespace std;
int array[10005];
int modulos(int a,int b)
{
	if(a < 0)
	{
		return b - abs(a)%b;
	}
	else
	{
		return a%b;
	}
}
int main()
{
	int n,k;
	cin>>n>>k;
	set<int> aye;
	memset(array,0,sizeof(array));
	for (int i = 0; i < n; ++i)
	{
		cin>>array[i];
	}
	aye.insert(array[n-1]%k);
	for(int i = n-2; i>= 0; i--)
	{
		set<int> naye;
		for(set<int>::iterator it = aye.begin(); it != aye.end(); it++)
		{
			int nk = *it;
			naye.insert(modulos(array[i]-nk,k));
			naye.insert(modulos(array[i]+nk,k));
		}
		aye = naye;
	}
	for (set<int>::iterator it = aye.begin(); it != aye.end(); it++)
	{
		if(*it == 0)
		{
			cout<<"Divisible"<<endl;
			return 0;
		}
	}
	cout<<"Not divisible"<<endl;
	return 0;

}