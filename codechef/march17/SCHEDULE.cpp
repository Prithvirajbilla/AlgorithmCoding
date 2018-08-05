#include <bits/stdc++.h>
using namespace std;

int T;

void print(set<pair<int,pair<int,int> > > b){
	for(set<pair<int,pair<int,int> > >::iterator it= b.begin(); it != b.end(); it++) {
		cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
	}
}

int main(){
	cin>>T;
	while(T--) {
		 int N,K;
		 cin>>N>>K;
		 string s;
		 cin>>s;
		 set<pair<int,pair<int,int> > > bst;
		 
		 int currentVal = s[0]-'0';
		 int prevPtr = 0;
		 int currentPtr = 1;
		 while(currentPtr < N) {
		 	while((currentPtr < N) && (s[currentPtr]-'0' == currentVal)) {
		 		currentPtr++;
		 	}
		 	bst.insert(make_pair(prevPtr-currentPtr,make_pair(currentVal,prevPtr)));

		 	if(currentPtr < N){
		 		prevPtr = currentPtr;
		 		currentVal = s[currentPtr]-'0';
		 	}
		 }
		 bst.insert(make_pair(prevPtr-currentPtr,make_pair(currentVal,prevPtr)));
		 int ans = -1;
		 for(int i=0; i< K; i++ ){
		 	set<pair<int,pair<int,int> > >::iterator it= bst.begin();
		 	if(abs(it->first) <= 2) {
		 		ans = 2;
		 		break;
		 	}
		 	else {
		 		if(abs(it->first)%2 == 1){
		 			bst.insert(make_pair(it->first/2,make_pair(it->second.first,it->second.second)));
		 			bst.insert(make_pair(it->first/2,make_pair(it->second.first,it->second.second+abs(it->first/2) + 1)));
		 			bst.insert(make_pair(-1,make_pair(!it->second.first,it->second.second+abs(it->first/2))));
		 			bst.erase(it);
		 		}
		 		else {
		 			bst.insert(make_pair(it->first/2,make_pair(it->second.first,it->second.second)));
		 			bst.insert(make_pair((it->first/2)+1,make_pair(it->second.first,it->second.second+abs(it->first/2) + 2)));
		 			bst.insert(make_pair(-1,make_pair(!it->second.first,it->second.second+abs(it->first/2))));
		 			bst.erase(it);
		 		}
		 	}
		 }
		 if(ans > 0)
		 	cout<<ans<<endl;
		 else {
		 	set<pair<int,pair<int,int> > >::iterator it = bst.begin();
		 	cout<<abs(it->first)<<endl;
		 }
	}
}