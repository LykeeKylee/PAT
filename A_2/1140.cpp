#include<bits/stdc++.h>
using namespace std;
int d, n;
string get_nth(int d, int n) {
	string ans;
	if(n == 1) ans = to_string(d);
	else {
		string tmp;
		ans = to_string(d);
		for(int i = 2; i <= n; ++i) {
			int cnt = 0;
			char c = ans[0];
			for(int j = 0; j < ans.length(); ++j) {
				if(ans[j] == c) ++cnt;
				else {
					tmp += c;
					tmp += to_string(cnt);
					cnt = 1;
					c = ans[j];
				}
			}
			tmp += c;
			tmp += to_string(cnt);
			ans = tmp;
			tmp.clear();
		}
	}
	return ans;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &d, &n);
	printf("%s\n", get_nth(d, n).c_str());
	return 0;
}
