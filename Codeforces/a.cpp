#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2;
	if(x1 == x2)
	{
		int side = abs(y1-y2);
		if(x1+side <= 1000)
		{
			x3 = x1+side;
		}
		else if(x1-side >= -1000)
		{
			x3 = x1-side;
		}
		else
		{
			cout<<-1<<endl;
			return 0;
		}
		x4 = x3;
		y3 = y1;
		y4 = y2;

	}
	else if(y1 == y2)
	{
		int side = abs(x1-x2);
		if(y1+side <= 1000)
		{
			y3 = y1+side;
		}
		else if(y1-side >= -1000)
		{
			y3 = y1-side;
		}
		else
		{
			cout<<-1<<endl;
			return 0;
		}
		y4 = y3;
		x3 = x1;
		x4 = x2;
	}
	else
	{
		if(abs(x1-x2) == abs(y1-y2))
		{
			x3 = x1;
			y3 = y2;
			x4 = x2;
			y4 = y1;
		}
		else
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;

}