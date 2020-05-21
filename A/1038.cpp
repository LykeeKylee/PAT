#include<bits/stdc++.h>
using namespace std;
bool cmp(string &a, string &b) {
	return a + b < b + a;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	vector<string> s(n);
	for(int i = 0; i < n; ++i) cin >> s[i];
	sort(s.begin(), s.end(), cmp);
	if(!s.empty()) {
		string ans;
		for(int i = 0; i < n; ++i) ans += s[i];
		int i = 0, j;
		while(i < ans.length() && ans[i] == '0') ++i;
		if(i != ans.length()) {
			j = i;
			while(j < ans.length()) printf("%c", ans[j++]);
		}
		else printf("0");
	}
	return 0;
}
