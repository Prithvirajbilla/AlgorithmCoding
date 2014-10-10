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
	ll* array = new ll[N];
	for (int i = 0; i < N; ++i)
	{
		frogs[i].id= i;
		cin>>frogs[i].x;
		array[i] = frogs[i].x;
	}
	sort(frogs,frogs+N,useasx);
	ll* max_distance = new ll[N];
	max_distance[frogs[N-1].id] = 0;
	for(int i = N-2; i >=0 ; i--)
	{
		if(frogs[i+1].x-frogs[i].x<= K)
		{
			max_distance[frogs[i].id] = frogs[i+1].x-frogs[i].x + max_distance[frogs[i+1].id];
		}
		else
		{
			max_distance[frogs[i].id] = 0;
		}
	}
/*for (int i = 0; i < N; ++i)
{
	cout<<max_distance[frogs[i].id]<<" ";
}
cout<<endl;
*/	for (int i = 0; i < P; ++i)
	{
		int A,B;
		cin>>A>>B;
		A--;B--;
		if(array[A]>array[B])
			swap(A,B);
		if(max_distance[A]+array[A] >= array[B])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

}