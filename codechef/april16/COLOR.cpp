#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin>>N;
		int R=0,G=0,B=0;
		for (int j = 0; j < N; ++j)
		{
			char c;
			cin>>c;
			if(c == 'R')
				R++;
			if(c == 'G')
				G++;
			if(c == 'B')
				B++;
		}
		cout<<min(R+G,min(R+B,G+B))<<endl;
	}
}