#include<bits/stdc++.h>
using namespace std;
int n, m, k, color[10005];
vector<pair<int, int>> edge;
//void dfs(int root) {
//	for(int i = 0; i < edge[root].size(); ++i) {
//		
//	}
//}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		edge.push_back(make_pair(x, y));
	}
	scanf("%d", &k);
	for(j = 0; j < k; ++j) {
		unordered_set<int> exColor;
		for(int c = 0; c < n; ++c) {
			scanf("%d", color + c);
			exColor.insert(color[c]);
		}
		bool flag = true;
		for(i = 0; i < edge.size() && flag; ++i) {
			flag = !(color[edge[i].first] == color[edge[i].second]);
		}
		if(flag) printf("%d-coloring\n", exColor.size());
		else printf("No\n");
	}
	return 0;
}
