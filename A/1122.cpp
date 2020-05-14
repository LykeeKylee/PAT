#include<bits/stdc++.h>
using namespace std;
bool graph[201][201];
int main() {
	int n, m, k, i, j, x, y;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		graph[x][y] = graph[y][x] = true;
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%d", &y);
		set<int> cnt;
		vector<int> path(y + 1);
		bool findx = true;
		for(j = 0; j < y; ++j) {
			scanf("%d", &path[j]);
			cnt.insert(path[j]);
		}
		if(path[0] != path[y - 1] || cnt.size() != n || y != n + 1) printf("NO\n");
		else {
			for(j = 1; j < y; ++j) {
				if(!graph[path[j-1]][path[j]]) {
					findx = false;
					break;
				}
			}
			if(findx) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
