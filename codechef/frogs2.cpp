#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int N,K,P;
    cin>>N>>K>>P;
    ll* array = new ll[N];
    ll* cp_array = new ll[N];
    for (int i = 0; i < N; ++i)
    {
        cin>>array[i];
        cp_array[i] = array[i];
    }
    ll *max_distance = new ll[N];
    sort(array,array+N);
    max_distance[N-1] = 0;
    for(int i = N-2; i >= 0; i--)
    {
        if(array[i+1]-array[i]<= K)
        {
            max_distance[i] = array[i+1]-array[i] + max_distance[i+1];
        }
        else
        {
        max_distance[i] = 0;
        }
    }
 for (int i = 0; i < N; ++i)
{
cout<<array[i]<<" ";
}
cout<<endl;
for (int i = 0; i < N; ++i)
{
cout<<max_distance[i]<<" ";
}
cout<<endl;
	
    for (int i = 0; i < P; ++i)
    {
        int A,B;
        cin>>A>>B;
        if(A  > B)
        {
            swap(A,B);
        }
        int wa = find(array,array+N,cp_array[A-1]) - array;
        //int wb = find(array,array+N,cp_array[B-1]) - array;
        if(max_distance[wa]+cp_array[A-1] >= cp_array[B-1])
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

} 

