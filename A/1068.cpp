#include<bits/stdc++.h>
using namespace std;
int coin[10005], dp[105];
bool selects[10005][105];
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; ++i) scanf("%d", coin + i);
	// 从大到小排序，小方案覆盖大方案
	sort(coin + 1, coin + 1 + n, greater<int>());
//	for(i = 1; i <= n; ++i) {
//		for(j = coin[i]; j <= m; ++j) {
//			if(dp[j] <= dp[j - coin[i]] + coin[i]) {
//				selects[i][j] = true;
//				dp[j] = dp[j - coin[i]] + coin[i];
//			}
//		}
//	}
//	for(i = 1; i <= n; ++i) {
//		for(j = 1; j <=m; ++j) cout << selects[i][j] << ' ';
//		cout << endl;
//	}
//	cout << endl;
	for(i = 1; i <= n; ++i) {
		for(j = m; j >= coin[i]; --j) {
			if(dp[j] <= dp[j - coin[i]] + coin[i]) {
				selects[i][j] = true;
				dp[j] = dp[j - coin[i]] + coin[i];
			}
		}
	}
//	for(i = 1; i <= n; ++i) {
//		for(j = 1; j <=m; ++j) cout << selects[i][j] << ' ';
//		cout << endl;
//	}

	if(dp[m] != m) printf("No Solution\n");
	else {
		i = n, j = m;
		vector<int> ans;
		while(j > 0) {
			if(selects[i][j]) {
				ans.emplace_back(coin[i]);
				j -= coin[i];
			}
			--i;
		}
		for(i = 0; i < ans.size(); ++i) printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
	}
	return 0;
}
