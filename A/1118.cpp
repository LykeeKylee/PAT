#include <bits/stdc++.h>
using namespace std;
int src[10005], cnt[10005];
bool birds[10005];
int findsrc(int x) {
	int cp = x;
	while(x != src[x]) x = src[x];
	while(cp != src[cp]) {
		int t = cp;
		cp = src[cp];
		src[t] = x;
	}
	return x;
}
void union_(int x, int y){
	int xs = findsrc(x), ys = findsrc(y);
	if(xs != ys) src[xs] = ys;
}
int main() {
	int n, k, q, i, j, first, x, y;
	scanf("%d", &n);
	for(i = 0; i < 10005; ++i) src[i] = i;
	for(i = 0; i < n; ++i) {
		scanf("%d %d", &k, &first);
		birds[first] = true;
		for(j = 0; j < k - 1; ++j) {
			scanf("%d", &x);
			birds[x] = true;
			union_(first, x);
		}
	}
	int tree = 0, birdsum = 0;
	for(i = 1; i < 10005; ++i) {
		if(birds[i]) {
			++birdsum;
			++cnt[findsrc(i)];
		}
	}
	for(i = 1; i < 10005; ++i) {
		if(cnt[i] != 0) ++tree;
	}
	printf("%d %d\n", tree, birdsum);
	scanf("%d", &q);
	for(i = 0; i < q; ++i) {
		scanf("%d %d", &x, &y);
		printf("%s\n", (findsrc(x) == findsrc(y) ? "Yes" : "No"));
	}
	return 0;
}
