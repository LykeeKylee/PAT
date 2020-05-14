#include <bits/stdc++.h>
using namespace std;
int graph[502][502], deg[502], visit[502], cnt = 0;
void dfs(int x, int n) {
	visit[x] = 1;
	++cnt;
	for(int i = 1; i <= n; ++i) {
		if(graph[x][i] == 0 || visit[i] == 1) continue;
		dfs(i, n);
	}
}
int main() {
	int n, m, i, j, x, y, odd = 0;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		graph[x][y] = graph[y][x] = 1;
		++deg[x];
		++deg[y];
	}
	dfs(1, n);
	for(i = 1; i <= n; ++i) {
		printf("%d%s", deg[i], (i == n ? "\n" : " "));
		if(deg[i] % 2 != 0) ++odd;
	}
	if(cnt != n || (cnt == n && odd != 2 && odd != 0)) printf("Non-Eulerian");
	else if(odd == 2) printf("Semi-Eulerian");
	else printf("Eulerian");
	return 0;
}
