#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//range update and range query
ll bit1[100005],bit2[100005];
int array[100005];
int n;

void update(ll* bit,int a, int v)
{
	while(a <= n)
	{
		bit[a]+=v;
		a += a & -a;
	}
}
ll query(ll* bit, int b)
{
	ll sum = 0;
	for(; b > 0; b -= b&(-b))
		sum += bit[b];
		
	return sum;
}
ll query_1(int a)
{
	return query(bit1,a)*a - query(bit2,a);
}
ll query_all(int a,int b)
{
	return query_1(b) - query_1(a-1);
}
void update_all(int a,int b,int v)
{
	update(bit1, a, v);
	update(bit1, b + 1, -v);
	update(bit2, a, v * (a-1));
	update(bit2, b + 1, -v * b); 
}

void init()
{
	for (int i = 1; i <= n ; ++i)
	{
		update(bit1, i, array[i]);
		update(bit1, i, -array[i]);
		update(bit2, i, array[i] * (i-1));
		update(bit2, i, -array[i] * i); 
	}
}
int main()
{
	cin>>n;
	memset(array,0,sizeof(array));
	memset(bit1,0,sizeof(bit1));
	memset(bit2,0,sizeof(bit2));
	for (int i =1; i <= n; ++i)
	{
		cin>>array[i];
	}
	int q;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		char c;int a,b;
		cin>>c>>a>>b;
		if(c == 'M')
		{
			cout<<query_all(a,b)<<endl;
		}
		else if(c == 'I')
		{
			update_all(a,b,1);
		}
		else if(c == 'E')
		{
			for (int i = a; i <= b ; ++i)
			{
				if(array[i]%2 == 1)
				{
					update_all(i,i,1);
					array[i]++;
				}
			}
		}
		else if(c == 'O')
		{
			for (int i = a; i <= b ; ++i)
			{
				if(array[i]%2 == 0)
				{
					update_all(i,i,1);
					array[i]++;
				}
			}
		}
	}
}