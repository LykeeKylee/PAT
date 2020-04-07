#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> chain;
map<int, int> cntLevel;
int minLevel = 999999999;
void dfs(int root, int level) {
	if(chain[root].size() == 0) {
		minLevel = level < minLevel ? level : minLevel;
		++cntLevel[level];
		return;
	}
	vector<int> *ptr = &chain[root];
	for(auto i = ptr->begin(); i != ptr->end(); ++i) dfs(*i, level + 1);
}
int main() {
	int n, k, i, j;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(i = 0; i < n; ++i) {
		scanf("%d", &k);
		chain[i].resize(k);
		for(j  = 0; j < k; ++j) scanf("%d", &chain[i][j]);
	}
	dfs(0, 0);
	p *= pow(1 + r / 100.0, minLevel);
	printf("%0.4lf %d\n", p, cntLevel[minLevel]);
	return 0;
}
