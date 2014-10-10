#include <bits/stdc++.h>
using namespace std;
int T;
#define mod 1000000007
#define ll long long int
ll gcd(ll a, ll b)
{
    for (;;)
    {
        if (a == 0) return b;
            b %= a;
        if (b == 0) return a;
            a %= b;
    }
}
 
ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);
 
    return temp ? (a / temp * b) : 0;
}
int main()
{
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int* array = new int[N+1];
        for (int i = 1; i < N+1; ++i)
        {
            cin>>array[i];
        }
        /* bool* taken = new bool[N+1];
        for (int i = 0; i < N+1; ++i)
        {
        taken[i] = false;
        }
        */  
        bool* taken = new bool[N+1];
    for (int i = 0; i < N+1; ++i)
    {
        taken[i] = false;
    }
        vector<int> num;
    int counter = 1;
    while(counter <= N)
    {
        int ans = 1;
        if(taken[counter])
        {
            counter++;
/*            cout<<counter<<endl;
*/            continue;
        }
            int start = counter;
            int real_start = start;
            taken[start] = true;
        while(array[start] != real_start)
        {
            start = array[start];
            taken[start] = true;
            ans++;
        }
        num.push_back(ans);
    }
        for (int i =0; i< num.size();i++)
        {
            if(num[i] != 1)
            {
            for (int j = i+1; j < num.size(); ++j)
            {
                num[j] /=__gcd(num[i],num[j]);
            }
        }
        }
        ll ans = 1;
        for (int i = 0; i < num.size(); ++i)
        {
            ans = (ans*num[i])%mod;
        }
        cout<<ans<<endl;
    }
 
}