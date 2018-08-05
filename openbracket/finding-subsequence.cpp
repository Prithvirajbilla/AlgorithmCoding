#include <bits/stdc++.h>

using namespace std;

string solve(string s, int k) {
	int count[26] = {0};
	vector<int> pos[26];
	for(int i =0; i < s.length(); i++) {
		count[s[i]-'a']++;
		pos[s[i]-'a'].push_back(i);
	}
	
	string ans;
	int currentPos = -1;
	for(int i = 25; i>=0 ; i--) {
		if(count[i] >= k) {
			if(currentPos == -1){
				for(int j =0; j<count[i]; j++) {
					char back = i +'a';
					ans += back;
				}
				currentPos = pos[i].back();
			}
			else {
				vector<int>::iterator it = upper_bound(pos[i].begin(), pos[i].end(), currentPos);
				char aa = i+'a';
				// cout<<aa<<" "<<(*it)<<" "<<currentPos<<endl;
				if(it != pos[i].end()) {
					int currentCount = (pos[i].end() - it);
					// cout<<currentCount<<endl;
					if(currentCount >= k) {
						for(int j =0; j<currentCount; j++) {
							char back = i +'a';
							ans += back;
						}
					}
					currentPos = pos[i].back();
				}
			}
		}
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	string result = solve(s, k);
	cout << result << endl;
	return 0;
}
