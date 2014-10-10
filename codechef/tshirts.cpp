#include <bits/stdc++.h>
using namespace std;
#define ll signed long long int
#define mod 1000000007
int n;
int nc_array[11];
ll product_of_all;
struct node
{
	int last;
	ll product;
	bitset<101> t;
};
node values[11][500];
void clr()
{
	memset(values,0,sizeof values);

}
vector<int> split(string &s, char delim)
{
	vector<int> elem;
	stringstream ss(s);
	string item;
	while(getline(ss,item,delim))
	{
		elem.push_back(atoi(item.c_str()));
	}
	return elem;
}
int fact(int n)
{
	if(n == 0)
		return 1;
	else
		return n*fact(n-1);
}
void fill_nc_array()
{
	for (int i = 0; i <= n; ++i)
	{
		nc_array[i] = fact(n)/(fact(i)*fact(n-i));
		cout<<nc_array[i]<<" ";
	}
	cout<<endl;
}
void do_stuff()
{
	for (int i = 2; i <= n; ++i)
	{
		int number = 1;
		for(int j = 1; j <= nc_array[i-1];j++)
		{
			for(int k = values[i-1][j].last+1; k<= n;k++)
			{
				node cur;
				cur.t = values[1][k].t & values[i-1][j].t;
				cur.product = values[i-1][j].product * values[1][k].product;
/*				cout<<cur.product<<" , ";
*/				cur.last = k;
				values[i][number] = cur;
				number++;
			}
/*			cout<<endl;
*/		}
	}
/*	cout<<"stuff"<<endl;
*/
	for (int i = 1; i <= n ; ++i)
	{
		for (int j = 1; j <= nc_array[i]; ++j)
		{
			cout<<values[i][j].last<<" : "<<values[i][j].product<<" : "<<values[i][j].t.count()<<" || ";
		}
		cout<<endl;
	}

}
void compute()
{
/*	cout<<product_of_all<<endl;
*/	ll answer = product_of_all;
	cout<<":::"<<answer<<endl;
	for (int i = 2; i <= n ; ++i)
	{
		for (int j = 1; j <= nc_array[i] ; ++j)
		{
			ll pr = product_of_all/values[i][j].product;
			ll a = pr * values[i][j].t.count();
			if(i%2 == 0)
			{
				a = -1*a;
			}
			cout<<a<<" , ";
			answer +=a;
		}
		cout<<endl;
		cout<<":::"<<answer<<endl;
	}
		cout<<answer<<endl;
	if(answer > 0)
	cout<<answer%mod<<endl;
	else
		cout<<0<<endl;
}
int main()
{
	int T;
	cin>>T;
/*	cout<<fact(10)<<endl;
*/	while(T--)
	{
		clr();
		cin>>n;
		product_of_all = 1;
		fill_nc_array();
		string end_line;
		getline(cin,end_line);
		for (int i = 1; i <= n; ++i)
		{
			string line;
			getline(cin,line);
			vector<int> integers = split(line,' ');
			node cur;
			for (int j = 0; j < integers.size(); ++j)
			{
				cur.t[integers[j]] = 1;
/*				cout<<integers[j]<<",";
*/
			}
/*			cout<<endl;
*/			cur.product = integers.size();
			product_of_all *= cur.product;
			cur.last = i;
			values[1][i] = cur;
		}
		do_stuff();
		compute();
	}
}
