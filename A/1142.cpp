#include <bits/stdc++.h>
using namespace std;
int graph[205][205], clique[205];
bool is_clique(int k) {
	int i, j;
	for(i = 0; i < k; ++i) {
		for(j = i + 1; j < k; ++j) {
			if(graph[clique[i]][clique[j]] == 0) return false;
		}
	}
	return true;
}
bool is_maximal(int k, int n, map<int, int> &v) {
	int i, j;
	for(i = 1; i <= n; ++i) {
		if(v[i] == 1) continue;
		int cnt = 0;
		for(j = 0; j < k; ++j) {
			if(graph[i][clique[j]] == 1) ++cnt;
		}
		if(cnt == k) return false;
	}
	return true;
}
int main() {
	int nv, ne, m, k, i, j;
	scanf("%d %d", &nv, &ne);
	for(i = 0; i < ne; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x][y] = graph[y][x] = 1;
	}
	scanf("%d", &m);
	for(i = 0; i < m; ++i) {
		scanf("%d", &k);
		map<int, int> v;
		for(j = 0; j < k; ++j) {
			scanf("%d", &clique[j]);
			v[clique[j]] = 1;
		}
		if(!is_clique(k)) printf("Not a Clique\n");
		else {
			if(is_maximal(k, nv, v)) printf("Yes\n");
			else printf("Not Maximal\n");
		} 
	}
	return 0;
}
