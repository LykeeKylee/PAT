#include<bits/stdc++.h>
using namespace std;
int n, m, coin[10005], dp[10005];
bool choice[10005][105];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; ++i) {
		scanf("%d", coin + i);
	}
	sort(coin + 1, coin + n + 1, greater<int>());
	for(i = 1; i <= n; ++i) {
		for(j = m; j >= coin[i]; --j) {
			if(dp[j] <= dp[j - coin[i]] + coin[i]) {
				choice[i][j] = true;
				dp[j] = dp[j - coin[i]] + coin[i];
			}
		}
	}
	if(dp[m] != m) printf("No Solution\n");
	else {
		 vector<int> ans;
		 int remain = m, idx = n;
		 while(remain > 0) {
		 	if(choice[idx][remain]) {
		 		ans.push_back(coin[idx]);
		 		remain -= coin[idx];
			 }
			 --idx;
		 }
		 for(i = 0; i < ans.size(); ++i) {
		 	printf("%s%d", i == 0 ? "" : " ", ans[i]); 
		 }
	}
	return 0;
} 
