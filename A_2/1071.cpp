#include<bits/stdc++.h>
using namespace std;
string str;
map<string, int> cnt;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for(i = 0; i < str.length(); ++i) {
		if(!isalnum(str[i])) continue;
		j = i;
		while(j < str.length() && isalnum(str[j])) ++j;
		string sub = str.substr(i, j - i);
		++cnt[sub];
		i = j;
	}
	string ans;
	int c = -1;
	for(auto m = cnt.begin(); m != cnt.end(); ++m) {
		if(m->second > c) {
			c = m->second;
			ans = m->first;
		}
	}
	printf("%s %d", ans.c_str(), c);
	return 0;
}
