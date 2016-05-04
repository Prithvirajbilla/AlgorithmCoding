#include <bits/stdc++.h>
using namespace std;
int T;
string A,B;
int main(int argc, char const *argv[])
{
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		cin>>A>>B;
		int check[256] = {0};
		for (int j = 0; j < A.length(); ++j)
		{
			check[A[j]] = 1;
		}
		bool isCheck= false;
		for (int j = 0; j < B.length(); ++j)
		{
			if(check[B[j]] != 0)
			{
				cout<<"Yes"<<endl;
				isCheck = true;
				break;
			}
		}
		if(!isCheck)
			cout<<"No"<<endl;
	}
	return 0;
}