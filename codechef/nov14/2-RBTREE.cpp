#include <bits/stdc++.h>
using namespace std;

int stage = 0;
char a,b;int x,y;
int len_bits(int x)
{
	int ans = 0;
	while(x > 0)
		x/=2,ans++;

	return ans;
}


void solve(int x1,int y1)
{
	int nb = 0,nr = 0;
	if(x1 > y1) swap(x1,y1);

	int lx1 = len_bits(x1);
	int ly1 = len_bits(y1);
	while(ly1 > lx1)
	{
		y1 = y1/2;
		ly1--;
	}
	
	while(x1 != y1)
	{
		x1 /= 2;
		y1 /= 2;
	}

	int lenx = len_bits(x);
	int leny = len_bits(y);
	int lenx1 = len_bits(x1);
	if(x1 == x || x1 == y)
	{
		if(lenx%2 == leny%2)
		{
			nb = (max(lenx,leny)-min(lenx,leny))/2 + (lenx%2 == 1)?1:0;
			nr = (max(lenx,leny)-min(lenx,leny))/2 + (lenx%2 == 0)?1:0;
		}
		else
		{
			nb = (max(lenx,leny)-min(lenx,leny))/2;
			nr = nb;
		}
	}
	else
	{
		if(lenx%2 == lenx1%2)
		{
			nb = (max(lenx,lenx1)-min(lenx,lenx1))/2 + (lenx%2 == 1)?1:0;
			nr = (max(lenx,lenx1)-min(lenx,lenx1))/2 + (lenx%2 == 0)?1:0;
		}
		else
		{
			nb = (max(lenx,lenx1)-min(lenx,lenx1)+1)/2;
			nr = nb;
		}

		if(leny%2 == lenx1%2)
		{
			nb += (max(leny,lenx1)-min(leny,lenx1))/2 + (leny%2 == 1)?1:0;
			nr += (max(leny,lenx1)-min(leny,lenx1))/2 + (leny%2 == 0)?1:0;
		}
		else
		{
			nb += (max(leny,lenx1)-min(leny,lenx1)+1)/2;
			nr += (max(leny,lenx1)-min(leny,lenx1)+1)/2;
		}

		if(lenx1%2 == 0)
			nr--;
		else
			nb--;
	}
	if(stage%2 == 0)
	{
		if(b == 'b')
		{
			cout<<nb<<endl;
		}
		else
		{
			cout<<nr<<endl;
		}
	}
	else
	{
		if(b == 'b')
		{
			cout<<nr<<endl;
		}
		else
		{
			cout<<nb<<endl;
		}
	}

}

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		cin>>a>>b;
		if(b == 'i')
		{
			stage++;
		}
		else
		{
			cin>>x>>y;
			solve(x,y);
		}
	}
}