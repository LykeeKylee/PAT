#include<bits/stdc++.h>
using namespace std;
int n, m, l, favorite[205], stripe[10005], dp[10005];
int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%d", &m);
	for(i = 0; i < m; ++i) {
		int c;
		scanf("%d", &c);
		favorite[c] = i + 1;
	}
	scanf("%d", &l);
	int cnt = 0;
	for(i = 0; i < l; ++i) {
		int c;
		scanf("%d", &c);
		if(favorite[c] != 0) stripe[cnt++] = c;
	}
	for(i = 0; i <= cnt; ++i) {
		dp[i] = 1;
		for(j = 0; j < i; ++j) {
			if(favorite[stripe[i]] >= favorite[stripe[j]])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	printf("%d", dp[cnt - 1]);
	return 0;
}
