#include<bits/stdc++.h>
using namespace std;
int cluster[1002];
map<int, vector<int>> hobby;
int findsrc(int x) {
	int y = x;
	while(x != cluster[x]) x = cluster[x];
	while(y != cluster[y]) {
		int tmp = y;
		y = cluster[y];
		cluster[tmp] = x;
	}
	return x;
}
void union_(int x, int y) {
	int xsrc = findsrc(x), ysrc = findsrc(y);
	if(xsrc != ysrc) cluster[xsrc] = cluster[ysrc];
}
int main() {
	int n, k, i, j, hi;
	scanf("%d", &n);
	for(i = 0; i < 1002; ++i) cluster[i] = i;
	for(i = 1; i <= n; ++i) {
		scanf("%d: ", &k);
		for(j = 0; j < k; ++j) {
			scanf("%d", &hi);
			hobby[hi].emplace_back(i);
		}
	}
	for(auto v = hobby.begin(); v != hobby.end(); ++v) {
		int first = v->second.front();
		for(i = 1; i < v->second.size(); ++i) {
			union_(first, (v->second)[i]); 
		}
	}
	vector<int> cnt(n + 1, 0);
	set<int> c;
	for(i = 1; i <= n; ++i) {
		int src = findsrc(i);
		++cnt[src];
		c.insert(src);
	}
	sort(cnt.begin(), cnt.end(), greater<int>());
	printf("%d\n", c.size());
	for(i = 0; i < c.size(); ++i) printf("%d%s", cnt[i], i == c.size() - 1 ? "\n": " ");
	return 0;
}
