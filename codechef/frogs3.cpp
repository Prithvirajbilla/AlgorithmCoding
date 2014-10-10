#include <bits/stdc++.h>
using namespace std;
#define ll long long int

typedef struct 
{
	int id;int x;
} Frog;
bool useasx(const Frog& a,const Frog& b)
{
	return a.x < b.x;
}
int main()
{
	int N,K,P;
	cin>>N>>K>>P;
	Frog* frogs = new Frog[N];
	for (int i = 0; i < N; ++i)
	{
		frogs[i].id= i;
		cin>>frogs[i].x;
	}
	sort(frogs,frogs+N,useasx);
	ll* max_distance = new ll[N];
	max_distance[frogs[0].id] = frogs[0].x+K;
	for(int i = 1; i < N; i++)
	{
		if(frogs[i].x-frogs[i-1].x<= K)
		{
			max_distance[frogs[i].id] = max_distance[frogs[i-1].id];
		}
		else
		{
			max_distance[frogs[i].id] = frogs[i].x+K;
		}
	}
for (int i = 0; i < N; ++i)
{
	cout<<max_distance[frogs[i].id]<<" ";
}
cout<<endl;
	for (int i = 0; i < P; ++i)
	{
		int A,B;
		cin>>A>>B;
		A--;B--;
		if(max_distance[A] == max_distance[B])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

}