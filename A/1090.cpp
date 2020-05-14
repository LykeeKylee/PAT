#include<bits/stdc++.h>
using namespace std;
int levels[100005], maxlevel = -1;
map<int, vector<int>> chain;
void cnt_level(int root, int level) {
	levels[root] = level;
	maxlevel = maxlevel > level ? maxlevel : level;
	for(int i = 0; i < chain[root].size(); ++i) cnt_level(chain[root][i], level + 1);
}
int main() {
	int n, i, root, x, cnt = 0;
	double p, r;
	scanf("%d %lf %lf", &n, &p, &r);
	for(i = 0; i < n; ++i) {
		scanf("%d", &x);
		if(x == -1) root = i;
		chain[x].emplace_back(i);
	}
	cnt_level(root, 0);
	for(i = 0; i < n; ++i) {
		if(levels[i] == maxlevel) ++cnt;
	}
	p *= pow(1.0 + r / 100.0, maxlevel);
	printf("%0.2lf %d\n", p, cnt);
	return 0; 
}
