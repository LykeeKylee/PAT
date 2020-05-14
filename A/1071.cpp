#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> word;
int main() {	string str, w, ans;
	int i, pos, cnt = -1;
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for(i = 0; i < str.length(); ++i) {
		if(isdigit(str[i]) || isalpha(str[i])) {
			pos = i;
			while(isdigit(str[i]) || isalpha(str[i])) ++i;
			w = str.substr(pos, i - pos);
			++word[w];
		}
	}
	for(auto m = word.begin(); m != word.end(); ++m) {
		if(m->second > cnt || (m->second == cnt && m->first < ans)) {
			cnt = m->second;
			ans = m->first;
		}
	}
	printf("%s %d\n", ans.c_str(), cnt);
	return 0;
}
