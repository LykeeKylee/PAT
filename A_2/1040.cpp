#include<bits/stdc++.h>
using namespace std;
string s;
int maxlen = 1;
bool judge(int low, int high) {
	int i = low;
	while(i <= high + low - i) {
		if(s[i] != s[high + low - i])
			return false;
		++i;
	}
	return true;
}
int dp[1005][1005];
void fill_dp() {
	int i, j, l, len = s.length();
	for(i = 0; i < len; ++i) {
		dp[i][i] = 1;
		if(i + 1 < len && s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
			maxlen = 2;
		}
	}
	for(l = 3; l <= len; ++l) {
		for(i = 0; i + l - 1 < len; ++i) {
			j = i + l - 1;
			if(s[i] == s[j] && dp[i + 1][j - 1]) {
				dp[i][j] = 1;
				maxlen = l;
			}
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	getline(cin, s);
//	for(i = 0; i < s.length(); ++i) {
//		for(j = i; j < s.length(); ++j) {
//			if(judge(i, j))
//				maxlen = maxlen < j - i + 1 ? j - i + 1: maxlen;
//		}
//	}
	fill_dp();
	cout << maxlen << endl;
	return 0; 
}
