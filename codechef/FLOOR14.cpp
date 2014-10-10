#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll get_number_n(ll n,ll m)
{
    ll p1 = n;
    ll p2 = n + 1;
    ll p3 = 2*n + 1;
    ll p4 = n + 2;
    ll p5 = n -1;
    ll p6 = 5;
    //result = (n*(n+1)*(2*n+1)*(3*(n**2)+3*n-1))/30
    switch(n%5)
    {
        case 0:
            p1 /= 5;
            break;
        case 1:
            p5 /= 5;
            p6 /= 5;
            break;
        case 2:
            p3 /= 5;
            break;
        case 3:
            p4 /= 5;
            p6 /= 5;
            break;
        case 4:
            p2 /= 5;
            break;
    }

    switch(n%2)
    {
        case 0:
            p1 /= 2;
            break;
        case 1:
            p2 /= 2;
            break;
    }

    switch(n%3)
    {
        case 0:
            p1 /= 3;
            break;
        case 1:
            p3 /= 3;
            break;
        case 2:
            p2 /= 3;
            break;
    }
    // cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<endl;
    // cout << 0%5 <<endl;
    ll result = 1;
    result *= p1;
    result %= m;
    result *= p2;
    result %= m;
    result *= p3;
    result %= m;
    result *= ((3*(p4%m * p5%m)%m)%m + p6);
    result %= m;
    return result; 

}
map<ll,ll> cal(ll n)
{
	map<ll,ll> a;
	for (int i = 1; i <= sqrt(n) ; ++i)
	{
		ll k = n/i;
		a.insert(pair<ll,ll>(k,1));
		ll d = n/i - n/(i+1);
		if (d != 0)
			a.insert(pair<ll,ll>(i,d));
	}
	return a;
}
// N sigma i = 1 to N (i)^4 *[floor(N/i)] N 10^10
pair<ll,ll>* cal_l(ll n)
{
    int q = sqrt(n);
    pair<ll,ll>* arr = new pair<ll,ll>[2*q];
    for (int i = 0; i < 2*q ; ++i)
    {
        arr[i] = pair<ll,ll>(0,0);
    }
    for (int i = 1; i <= q ; ++i)
    {
        ll d = n/i - n/(i+1);
        if (d != 0)
        {
            arr[i-1] = pair<ll,ll>(i,d);
            // cout<<i<<endl;
        }
        ll k = n/i;
        if(k <= q)
        {
            if(arr[k-1].first == 0)
            {

                arr[2*q-i] = pair<ll,ll>(k,1);
                // cout<<2*q-i<<endl;
            }
        }
        else
        {
            arr[2*q-i] = pair<ll,ll>(k,1);
            // cout<<2*q-i<<endl;
        }
    }
    // for (int i = 0; i < 2*q; ++i)
    // {
    //     cout<<arr[i].first<<" : "<<arr[i].second<<" , ";
    // }
    // cout<<endl;
    return arr;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		ll n,m;
		cin>>n>>m;
		pair<ll,ll>* that_dict = cal_l(n);
		ll count = 0,number = n,result = 0;
        ll q = sqrt(n);
		for (int i =0; i< 2*q; i++)
		{
            if (that_dict[i].first == 0)
                continue;
			ll part = get_number_n(number,m);
			number -= that_dict[i].second;
			result += (that_dict[i].first - count)*part;
			result %= m;
			count += (that_dict[i].first -count);
		}
		cout<<result<<endl;
	}
	return 0;
}