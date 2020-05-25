#include<bits/stdc++.h>
using namespace std;
int p[1005], hobby[1005];
int finds(int x) {
	int y = x, tmp;
	while(x != p[x]) x = p[x];
	while(y != p[y]) {
		tmp = p[y];
		p[y] = x;
		y = p[tmp];
	}
	return x;
}
void unionize(int x, int y) {
	int xs = finds(x), ys = finds(y);
	if(xs != ys) p[ys] = xs;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, i, j, k, h;
	scanf("%d", &n);
	for(i = 0; i < 1005; ++i) p[i] = i;
	for(i = 1; i <= n; ++i) {
		scanf("%d:", &k);
		for(j = 0; j < k; ++j) {
			scanf("%d", &h);
			if(hobby[h] == 0) hobby[h] = i;
			else unionize(hobby[h], i);
		}
	}
	set<int> cluster;
	vector<int> ans(n + 1, 0);
	for(i = 1; i <= n; ++i) {
		int src = finds(i);
		cluster.insert(src);
		ans[src]++;
	}
	sort(ans.begin(), ans.end(), greater<int>());
	printf("%d\n", cluster.size());
	for(i = 0; i < cluster.size(); ++i) printf("%d%s", ans[i], i == cluster.size() - 1 ? "\n":" ");
	return 0;
} 
