#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	int rm = b/2;
	set<int> rem;
	while(a%b != 0)
	{
		a += a%b;
		pair<set<int>::iterator,bool> h = rem.insert(a%b);
		if(h.second == false)
			break;
	}
	if(a%b == 0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}