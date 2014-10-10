#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin>>N;
		string res;
		for(int j = N;j >= 0 ; j--)
		{
			if(j%3 ==0 && (N-j)%5 == 0)
			{
				res = "";
				for (int k = 0; k < j; ++k)
				{
					res+='5';
				}
				for (int k = 0; k < N-j; ++k)
				{
					res+='3';
				}
				break;
			}
		}
		if(res == "")
			cout<<-1<<endl;
		else
			cout<<res<<endl;
	}
	return 0;
}