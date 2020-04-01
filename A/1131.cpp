#include<bits/stdc++.h>
using namespace std;
map<int, vector<int>> subway;
map<int, map<int, int>> lines;
bool visit[10005];
vector<int> minPath;
vector<int> minLine;
int mintransferCnt = 999999999, minCnt = 999999999;
void dfs(int cur, int pre, int y, int transferCnt, int cnt, vector<int> path, vector<int> line) {
	if(cur == y) {
		line.emplace_back(lines[pre][cur]);
		path.emplace_back(cur);
		if(cnt < minCnt || (cnt == minCnt && transferCnt < mintransferCnt)) {
			minPath = path;
			mintransferCnt = transferCnt;
			minCnt = cnt;
			minLine = line;
		}
		return;
	}
	++cnt;
	visit[cur] = true;
	for(auto i = subway[cur].begin(); i != subway[cur].end(); ++i) {
		if(visit[*i]) continue;
		if(pre != -1 && lines[cur][*i] != lines[pre][cur]) {
			++transferCnt;
			line.emplace_back(lines[pre][cur]);
			path.emplace_back(cur);
		}
		dfs(*i, cur, y, transferCnt, cnt, path, line);
		visit[*i] = false;
		if(pre != -1 && lines[cur][*i] != lines[pre][cur]) {
			--transferCnt;
			line.pop_back();
			path.pop_back();
		}
	}
}
int main() {
	int n, m, k, i, j, x, y;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &m);
		int tmp, stop;
		for(j = 1; j <= m; ++j) {
			scanf("%d", &stop);
			if(j == 1) tmp = stop;
			else {
				subway[tmp].emplace_back(stop);
				subway[stop].emplace_back(tmp);
				lines[tmp][stop] = lines[stop][tmp] = i;
				tmp = stop;
			}
		}
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%d %d", &x, &y);
		fill(visit, visit + 10005, false);
		mintransferCnt = 999999999;
		minCnt = 999999999;
		minLine.clear();
		minPath.clear();
		dfs(x, -1, y, 0, 0, vector<int>(1, x), vector<int>());
		cout << minCnt << endl;
		for(j = 0; j < minLine.size(); ++j) printf("Take Line#%d from %04d to %04d.\n", minLine[j], minPath[j], minPath[j+1]);
	}
	return 0;
}
