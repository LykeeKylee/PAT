#include<bits/stdc++.h>
using namespace std;
int n;
string ans;
vector<string> s;
bool cmp(string &a, string &b) {
	return a.length() < b.length();
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	getchar();
	for(i = 0; i < n; ++i) {
		string t;
		getline(cin, t);
		s.push_back(t);
	}
	sort(s.begin(), s.end(), cmp);
	bool flag = true;
	for(i = 0; i < s[0].length(); ++i) {
		for(j = 1; j < s.size(); ++j) {
			if(s[0][s[0].length() - 1 - i] != s[j][s[j].length() - 1 - i]) {
				flag = false;
				break;
			}
		}
		if(!flag) break;
		ans = s[0][s[0].length() - 1 - i] + ans;
	}
	if(ans.length() == 0) printf("nai");
	else printf("%s", ans.c_str());
	return 0;
}
