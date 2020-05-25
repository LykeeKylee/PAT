#include<bits/stdc++.h>
using namespace std;
int bird[10005];
bool visit[10005];
int find_src(int x) {
	int y = x, tmp;
	while(x != bird[x]) x = bird[x];
	while(y != bird[y]) {
		tmp = bird[y];
		bird[y] = x;
		y = bird[tmp];
	}
	return x;
}
void unionize(int x, int y) {
	int xs = find_src(x), ys = find_src(y);
	if(xs != ys) bird[ys] = xs;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, k, q, i, j, x, y, cnt = 0;
	for(i = 0; i < 10005; ++i) bird[i] = i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d %d", &k, &x);
		visit[x] = true;
		for(j = 1; j < k; ++j) {
			scanf("%d", &y);
			unionize(x, y);
			visit[y] = true;
		} 
	}
	set<int> tree;
	for(i = 1; i < 10005; ++i) {
		if(visit[i]) {
			tree.insert(find_src(i));
			++cnt;
		}
	}
	printf("%d %d\n", tree.size(), cnt);
	scanf("%d", &q);
	for(i = 0; i < q; ++i) {
		scanf("%d %d", &x, &y);
		printf("%s\n", find_src(x) == find_src(y) ? "Yes" : "No");
	}
	return 0;
} 
