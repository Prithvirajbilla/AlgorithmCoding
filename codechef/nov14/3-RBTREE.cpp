#include <bits/stdc++.h>
using namespace std;
char a,b;int x,y;
int len_bits(int x)
{
	int ans = 0;
	while(x > 0)
		x/=2,ans++;
	return ans;
}
void solve(int x1,int y1,int b)
{
	if(x1 > y1)
		swap(x1,y1);

	int ret = 0;

	int lx1 = len_bits(x1);
	int ly1 = len_bits(y1);

	while(ly1 > lx1)
	{
		if(ly1%2 == b) ret++;
		y1 = y1/2;
		ly1--;
	}

	while(lx1 > 0)
	{
		if(lx1%2 == b) ret++;
		if(ly1%2 == b) ret++;
		if(x1 == y1)
		{
			if(lx1%2 == b)
				ret--;
			break;
		}
		x1 /= 2;
		y1 /= 2;
		lx1--;
		ly1--;
	}

	cout<<ret<<endl;
}
int main()
{
	int q;
	cin>>q;
	int black = 1;
	while(q--)
	{
		cin>>a>>b;
		if(b == 'i')
		{
			black ^= 1;
		}
		else
		{
			cin>>x>>y;
			if(b == 'b')
			{
				solve(x,y,black);
			}
			else
			{
				solve(x,y,black^1);
			}
		}
	}
	return 0;
}