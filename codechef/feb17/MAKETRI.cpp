#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>


ll A[1000005];
ll intersect(ll a, ll b, ll l, ll r){
	if(b < l) return 0;
	if(a > r) return 0;
	ll l1 = l, r1 = r;
	if(a >= l) l1 = a;
	else l1 = l;

	if(b <= r) r1 = b;
	else r1 = r;

	return r1-l1+1;
}

bool union_set(ll a1, ll b1, ll number){
	if(a1 <= number && number <= b1) return true;
	else return false;
}

pll union_this(pll a, pll b) {
	if(a.second >= b.first) {
		return pll(a.first,max(a.second,b.second));
	}
	return pll(0,0);
}

int main(){
	ll N,L,R;
	cin>>N>>L>>R;
	memset(A, 0, sizeof(A));
	for (int i = 0; i < N; ++i)
	{
		cin>>A[i];
	}
	sort(A,A+N);
	set<pll> interval;
	interval.insert(pll(A[N-1]-A[N-2]+1,A[N-1]+A[N-2]-1));

	for(int i = N-2; i > 0; i--) {
		ll x = A[i]- A[i-1]+1;
		ll y = A[i]+A[i-1]-1;
		if(interval.find(pll(x,y)) == interval.end()) 
		{
			bool check = true;
			// cout<<"start"<<endl;
			for(set<pll>::iterator it = interval.begin();it != interval.end();it++)
			{
				pll ans;
				if(*it < pll(x,y)) {
					ans = union_this(*it,pll(x,y));
				}
				else {
					ans = union_this(pll(x,y), *it);
				}
				// cout<<it->first<<" "<<it->second<<":"<<x<<" "<<y<<endl;
				// cout<<ans.first<<" "<<ans.second<<endl;
				if(ans != pll(0,0)) {
					interval.erase(it);
					interval.insert(ans);
					check = false;
					break;
				}
			}
			if(check) interval.insert(pll(x,y));
			// cout<<"end"<<endl;
		}
	}
	ll result = 0;
	for(set<pll>::iterator it = interval.begin();it != interval.end();it++) {
		result += intersect(it->first,it->second,L,R);
	}
	cout<<result<<endl;
	return 0;
}