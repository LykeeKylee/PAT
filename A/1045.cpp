#include<bits/stdc++.h>
using namespace std;
int eva[205], dp[10005], stripe[10005];
bool colors[205];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, m, l, i, j, len = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for(i = 0; i < m; ++i) {
		scanf("%d", &j);
		colors[j] = true;
		eva[j] = i;
	}	
	scanf("%d", &l);
	for(i = 0; i < l; ++i) {
		scanf("%d", &j);
		if(colors[j]) stripe[len++] = j;
	}
	for(i = 0; i < len; ++i) {
		dp[i] = 1;
		for(j = 0; j < i; ++j) {
			if(eva[stripe[i]] >= eva[stripe[j]]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	printf("%d\n", dp[len - 1]);
	return 0;
}
