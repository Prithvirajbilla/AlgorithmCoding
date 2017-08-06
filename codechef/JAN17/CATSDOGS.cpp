#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int T;
	cin>>T;
	for(int i=0; i< T; i++)
	{
		ll C,D,L;
		cin>>C>>D>>L; 
		ll rem = 4*(D+C) -L;
		if(rem > 0 && L%4 ==0 && rem%4 == 0 && rem/4 <= 2*D && rem/4 <= C ){
			cout<<"yes"<<endl;
		}
		else if(rem == 0)
			cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}