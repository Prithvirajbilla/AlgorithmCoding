#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string a,b;
		cin>>a;
		b = a;
		next_permutation(a.begin(),a.end());
		if(a.compare(b) <= 0 )
			cout<<"no answer"<<endl;
		else
			cout<<a<<endl;
	}
}