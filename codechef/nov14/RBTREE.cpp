#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int stage = 0;
char a,b;
ll x,y;
//initially red root and black nodes.
void get_balls()
{
	vector<ll> px,py;
	ll tx = x,ty=y;
	while(tx > 0)
	{
		px.push_back(tx);
		tx/=2;
	}
	while(ty > 0)
	{
		py.push_back(ty);
		ty/=2;
	}
	// for (int i = 0; i < px.size(); ++i)
	// {
	// 	cout<<px[i]<<" ";
	// }
	// cout<<endl;
	// for (int i = 0; i < py.size(); ++i)
	// {
	// 	cout<<py[i]<<" ";
	// }
	// cout<<endl;

	int i = 0;
	int nx = px.size();
	int ny = py.size();
	while(i < nx && i < ny && px[nx-i-1] == py[ny-i-1])
	{
		i++;
	}
	int root_node = 0;
	int nb = 0,nr = 0;
	if(i == nx)
	{
		root_node = x;
		if(nx%2 == 0 && ny%2 == 0) //black
		{
			nb = 2 + (ny-nx-1)/2;
			nr = ny-nx+1-nb;
		}
		else if(nx%2 == 1 && ny%2 == 1)
		{
			nr = 2 + (ny-nx-1)/2;
			nb = ny-nx+1-nr;
		}
		else //red =1
		{
			nr = (ny-nx+1)/2;
			nb = (ny-nx+1)/2;
		}
	}
	else if(i == ny)
	{
		root_node = y;
		if(nx%2 == 0 && ny%2 == 0) //black
		{
			nb = 2 + (nx-ny-1)/2;
			nr = nx-ny+1-nb;
		}
		else if(nx%2 == 1 && ny%2 == 1)
		{
			nr = 2 + (nx-ny-1)/2;
			nb = nx-ny+1-nr;
		}
		else //red =1
		{
			nr = (nx-ny+1)/2;
			nb = (nx-ny+1)/2;
		}
	}
	else
	{
		root_node = px[nx-i];
		// that is i+1
		// cout<<i<<endl;
		if(i%2 == 0 && nx%2 == 0)
		{
			nb = 2+(nx-i-1)/2;
			nr = nx-i+1-nb;
		}
		else if(nx%2 == 1 && i%2 == 1)
		{
			nr = 2+(nx-i-1)/2;
			nb = nx-i+1-nr;
		}
		else //red =1
		{
			nr = (nx-i+1)/2;
			nb = (nx-i+1)/2;
		}
		if(i%2 == 0 && ny%2 == 0)
		{
			nb += 2+(ny-i-1)/2;
			nr += ny-i+1-(2+(ny-i-1)/2);
		}
		else if(ny%2 == 1 && i%2 == 1)
		{
			nr += 2+(ny-i-1)/2;
			nb += ny-i+1-(2+(ny-i-1)/2);
		}
		else //red =1
		{
			nr += (ny-i+1)/2;
			nb += (ny-i+1)/2;
		}
		if(i%2 == 0)
		{
			nb--;
		}
		else
		{
			nr--;
		}
	}
	// cout<<"root_node "<<root_node<<endl;
	// cout<<nb<<" "<<nr<<endl;
	if(stage%2 == 1 && b == 'b')
	{
		cout<<nb<<endl;
	}
	else if(stage%2 == 1 && b == 'r')
	{
		cout<<nr<<endl;
	}
	else if(stage%2 == 0 && b == 'b')
	{
		cout<<nr<<endl;
	}
	else if(stage%2 == 0 && b == 'r')
	{
		cout<<nb<<endl;
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
			/*cout<<*/get_balls()/*<<endl*/;
		}
	}
	return 0;
}