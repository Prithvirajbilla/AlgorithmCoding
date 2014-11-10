#include <iostream>
using namespace std;

int main()
{
	string a[10000];
	int i =0;
	while(!cin.eof())
	{
		cin>>a[i];
		i++;
	}
	int arr[9]= {0,1,2,5,8,7,6,3,4};
	for(int j=0;j<i;j++)
	{
		for(int k=0;k<9;k++)
		{
			cout<<a[j+arr[k]]<<" ";
		}
		j+=8;
	}
	cout<<endl;
    return 0;
}
