#include<bits/stdc++.h>
using namespace std;
map<int, vector<int>> graph;
int main() {
	int n, m, k, nv, i, j, v, q, x, y;
	scanf("%d %d", &n, &m);
	vector<int> degree(n, 0);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		graph[x].emplace_back(y);
		graph[y].emplace_back(x);
		++degree[x];
		++degree[y];
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%d", &nv);
		vector<int> dtmp(degree.begin(), degree.end());
		for(j = 0; j < nv; ++j) {
			scanf("%d", &q);
			dtmp[q] = 0;
			vector<int> edge = graph[q];
			for(auto e = edge.begin(); e != edge.end(); ++e) --dtmp[*e];
		}
		for(j = 0; j < n; ++j) {
			if(dtmp[j] > 0) {
				printf("No\n");
				break;
			}
		}
		if(j == n) printf("Yes\n");
	}
	return 0;
}
