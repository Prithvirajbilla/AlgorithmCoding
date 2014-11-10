#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int  array[3] = {0};
		for (int i = 0; i < n; ++i)
		{
			char a;
			cin>>a;
			if(a == 'N')
				array[0]++;
			else if(a == 'Y')
				array[1]++;
			else if(a == 'I')
				array[2]++;
		}
		if(array[2] != 0)
		{
			cout<<"INDIAN"<<endl;
		}
		else if(array[1] != 0)
		{
			cout<<"NOT INDIAN"<<endl;
		}
		else
		{
			cout<<"NOT SURE"<<endl;
		}
	}
	return 0;
}