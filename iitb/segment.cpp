#include <bits/stdc++.h>
using namespace std;
int arr[105];
int a[1<<7][10];
string str[10]={
"1111110",
"0110000",
"1101101",
"1111001",
"0110011",
"1011011",
"1011111",
"1110000",
"1111111",
"1111011"
};
void fill()
{
	for (int i = 0; i < 10; ++i)
	{
		bitset<7> s2(str[10-i-1]);
		a[0][i] = s2.to_ulong();
	}
	for(int i=0; i < 128;i++)
	{
		for (int j = 0; j < 10; ++j)
		{
			a[i][j] = a[0][j] & (~i);
		}
	}
	for (int i = 0; i < 128; ++i)
	{
		cout<<i<<": ";
		for (int j = 0; j < 10; ++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int T;
	cin>>T;
	int cas;
	fill();
	for(cas = 1; cas <= T;cas++)
	{
		int n;
		cin>>n;
		memset(arr,0,sizeof(arr));
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			bitset<7> k(s);
			arr[i] = k.to_ulong();
		}
		if(n <= 10)
		{
			int found = 0;
			set<int> req;
			for (int i = 0; i < 128; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					bool am = true;
					int k;
					for (k = 0; k < n; ++k)
					{
						if(arr[k] != a[i][(j+k)%10])
						{
							am = false;
							break;
						}
					}
					if(am)
					{
						req.insert(a[i][(j+k)%10]);
					}
					if(req.size() > 1)
						break;
				}
				if(req.size() > 1)
					break;
			}
			// for (set<int>::iterator it= req.begin(); it != req.end() ; ++it)
			// {
			// 	cout<<(*it)<<" ";
			// }
			// cout<<endl;
			if(req.size() != 1)
			{
				cout<<"Case #"<<cas<<": ERROR!"<<endl;
			}
			else
			{
				bitset<7> k(*req.begin());
				cout<<"Case #"<<cas<<": "<<k.to_string()<<endl; 
			}
		}
		else
		{
			//check for ambiguity:
			//1. repeating samely;
			// bool ambiguos = false;
			// for (int i = 10; i < n; ++i)
			// {
			// 	if(arr[i] != arr[i%10])
			// 	{
			// 		ambiguos = true;
			// 		break;
			// 	}
			// }
			// if(ambiguos)
			// {
			// 	cout<<"Case #"<<cas<<": ERROR!"<<endl;
			// 	continue;
			// }
			bool ambiguos = true;
			for (int i = 0; i < 128 ; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					ambiguos = true;
					for(int k=0; k< n; ++k)
					{
						if(arr[k] != a[i][(j+k)%10])
						{
							ambiguos = false;
							break;
						}
					}
					if(ambiguos)
					{
						break;
					}
				}
				if(ambiguos)
				{
					break;
				}
			}
			if(ambiguos)
			{
				bitset<7> k(arr[n%10]);
				cout<<"Case #"<<cas<<": "<<k.to_string()<<endl; 
			}
			else
			{
				cout<<"Case #"<<cas<<": ERROR!"<<endl;
			}
		}
	}
}