#include <bits/stdc++.h>
using namespace std;
int T;

int main() {
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int zeros = 0;
		for(int i=0; i< N;i++){
			for(int j=0; j< N; j++)
			{
				int k;
				cin>>k;
				if(k == 0)
					zeros++;
			}
		}
		int now = 0;
		while(true) {
			now++;
			int vals = (now == N)? now:now*2;
			if(zeros >= vals) {
				zeros -= vals;
			}
			else {
				now--;
				break;
			}
		}
		if(now == N) cout<<0<<endl;
		else {
			cout<<N-now-1<<endl;
		}

	}
	return 0;
}