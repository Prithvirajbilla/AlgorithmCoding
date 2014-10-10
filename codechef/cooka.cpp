#include <bits/stdc++.h>
using namespace std;
bool myfunction(pair<int,int> i,pair<int,int> j)
{
	return (i.first < j.first);
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		int* array = new int[n+1];
		for (int i = 1; i <= n; ++i)
		{
			cin>>array[i];
		}
		pair<int,int>* perm = new pair<int,int>[m];
		for (int i = 0; i < m; ++i)
		 {
		 	int a,b;
		 	cin>>a>>b;
		 	perm[m].first = a;perm[i].second = b;
		 }
/*		 int* max_array = new int[n+1];
		 max_array[1] = array[1];
		 for (int i =2; i <= n ; ++i)
		 {
		 	if(max_array[i-1] > array[i])
		 	{
		 		max_array[i] = array[i];
		 	}
		 	else
		 		max_array[i] = max_array[i-1];
		 }
*/		 sort(perm,perm+m,myfunction);
		 bool* possible = new bool[n+1];
		 fill(possible,possible+n+1,false);
		 for (int i = 1; i <= n ; ++i)
		 {
		 	int f,e;
		 	if(array[i] > i)
		 	{
		 		f = i;
		 		e = array[i];
		 	}
		 	else
		 	{
		 		f = array[i];
		 		e = i;
		 	}
		 	for (int j = 0; j < m; ++j)
		 	{
		 		if(f >= perm[j].first && f <= perm[j].second && e >= perm[j].first && e <= perm[j].second)
		 		{
		 			possible[i] = true;
		 			break;
		 		}
		 	}
		 }
		 bool val = true;
		 for (int i = 1; i <= n; ++i)
		 {
		 	val &= possible[i];
		 }
		 if(val)
		 {
		 	cout<<"Possible"<<endl;
		 }
		 else
		 {
		 	cout<<"Impossible"<<endl;
		 }
	}	
	return 0;
}