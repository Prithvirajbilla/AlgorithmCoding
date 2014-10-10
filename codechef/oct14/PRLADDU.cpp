#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int* d = new int[n];
		queue<int> dino,vil;
		for (int i = 0; i < n; ++i)
		{
			cin>>d[i];
			if(d[i] > 0)
			{
				vil.push(i);
			}
			else
			{
				dino.push(i);
			}

			d[i] = abs(d[i]);
		}
		long long int cost = 0;
		while(!vil.empty())
		{
			int vi = vil.front();
			int di = dino.front();
			if(d[di] > d[vi])
			{
				cost += d[vi]*abs(di-vi);
				d[di] = d[di]-d[vi];
				d[vi] = 0;
				vil.pop();
			}
			else
			{
				cost += d[di]*abs(di-vi);
				d[vi] = d[vi] - d[di];
				d[di] = 0;
				dino.pop();
				if(d[vi] == 0)
				{
					vil.pop();
				}

			}
			// cout<<"cost: "<<cost<<endl;
		}
		cout<<cost<<endl;
	}
	return 0;
} 