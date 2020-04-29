#include<bits/stdc++.h>
using namespace std;
set<int> cnt[52];
int main() {
	int n, m, k, i, j, x, y, same;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &m);
		for(j = 0; j < m; ++j) {
			scanf("%d", &x);
			cnt[i].insert(x);
		}
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%d %d", &x, &y);
		same = 0;
		for(auto s = cnt[x].begin(); s != cnt[x].end(); ++s) {
			if(cnt[y].find(*s) != cnt[y].end()) ++same;
		}
		printf("%.1lf%%\n", same * 1.0 / (cnt[x].size() + cnt[y].size() - same) * 100.0 + 0.01);
	}
	return 0;
}
