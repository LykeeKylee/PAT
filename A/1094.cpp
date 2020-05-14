#include<bits/stdc++.h>
using namespace std;
map<int, vector<int>> pedigree;
map<int, int> levels;
void levelCnt(int root, int level) {
	++levels[level];
	for(int i = 0; i < pedigree[root].size(); ++i) 
		levelCnt(pedigree[root][i], level + 1);
}
int main() {
	int n, m, k, i, j, p;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &p, &k);
		pedigree[p].resize(k);
		for(j = 0; j < k; ++j) scanf("%d", &pedigree[p][j]);
	}
	levelCnt(1, 1);
	i = j = -1;
	for(auto m = levels.begin(); m != levels.end(); ++m) {
		if(m->second > i) {
			i = m->second;
			j = m->first;
		}
	}
	printf("%d %d\n", i, j);
	return 0;
}
