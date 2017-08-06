#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
int m;
ll a[500010];
ll ta[500010];
ll BIT[500010];
ll ans[500010];
int cnt;

ll prefix(ll bposn) {
	if(bposn<=0) return 0;
    if(bposn>cnt) bposn=cnt;

    int ret=0;
    for(int i=bposn; i>0; i-=((i)&(-i)))
        ret+=BIT[i];
    return ret;
}

void update(int bposn, int bincr)
{
    if(bposn<=0) return;
    if(bposn>cnt) return;

    for(int i=bposn; i<=cnt; i+=((i)&(-i)))
        BIT[i]+=bincr;
}

ll query(ll bl, ll br) {
	if(br<=0 or bl>cnt or bl>br) return 0;
	if(bl<=0) bl=1;
	if(br>cnt) br=cnt;
	return (prefix(br)-prefix(bl-1));
}

int main() {
	memset(a, 0, sizeof a);
	memset(BIT, 0, sizeof BIT);
	memset(ans, 0, sizeof ans);
	memset(ta, 0, sizeof ta);

	cin>>n>>m;
	for(int i =0; i< n; i++) {
		cin>>a[i];
		ta[i] = a[i];
	}
	sort(ta, ta+n);
	cnt = int(unique(ta,ta+n)-ta);

	for(int i =0; i< n; i++) {
		a[i] = 1+ int(lower_bound(ta,ta + cnt, a[i])-ta);
		// cout<<a[i]<<" ";
	}
	// cout<<endl;
	

	ans[0] = 0;
    for(int i =0; i< m; i++) {
        ans[0] += query(a[i]+1, cnt);
        update(a[i],1);
    }

    for(int i = 1; i<= n-m; i++) {
		
		ans[i] = ans[i-1];
			
	    int li = i-1;
	    ans[i] -= query(1, a[li]-1);
	    update(a[li], -1); 

	    int ri = i+m-1;
	    ans[i] += query(a[ri]+1, cnt+1);
	    update(a[ri], 1);
	}

    ll ans_sum = 0;
    for(int i =0; i<= n-m; i++) {
        ans_sum += ans[i];
    }
    cout<<ans_sum<<endl;
    return 0;
}