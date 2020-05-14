#include<bits/stdc++.h>
using namespace std;
const int inf = 999999999;
int n, m, k, ds, best_station = -1;
double best_min = -1.0, best_avg = -1.0;
vector<pair<int, int>> road[1020];
bool visit[1020];
int nameMapping(string a) {
	if(isalpha(a[0])) {
		a[0] = '0';
		while(a.length() < 3) a = '0' + a;
		a = '1' + a;
	}
	return atoi(a.c_str());
}
void dijkstra(int root) {
	int distance[1020], left = n + m, cur_min = inf, cur_len = 0;
	fill(distance, distance + 1020, inf);
	fill(visit, visit + 1020, false);
	distance[root] = 0;
	while(left > 0) {
		int cur = inf, curdist = inf;
		for(int i = 1; i <= n; ++i) {
			if(!visit[i] && distance[i] < curdist) {
				curdist = distance[i];
				cur = i;
			}
		}
		for(int i = 1001; i <= 1000 + m; ++i) {
			if(!visit[i] && distance[i] < curdist) {
				curdist = distance[i];
				cur = i;
			}
		}
		if(cur == inf) return;
		visit[cur] = true;
		for(int i = 0; i < road[cur].size(); ++i) {
			int end = road[cur][i].first, dist = road[cur][i].second;
			if(!visit[end] && curdist + dist < distance[end]) distance[end] = curdist + dist;
		}
		--left;
	}
	bool flag = true;
	for(int i = 1; i <= n; ++i) {
		if(distance[i] > ds) {
			flag = false;
			break;
		}
		cur_len += distance[i];
		cur_min = distance[i] < cur_min ? distance[i] : cur_min;
	}
	double cur_avg = cur_len * 1.0 / n;
	if(flag && (cur_min * 1.0 > best_min || (cur_min * 1.0 == best_min && cur_avg < best_avg))) {
		best_station = root;
		best_min = cur_min * 1.0;
		best_avg = cur_avg * 1.0;
	}
}
int main() {
	int i, j;
	string p1, p2;
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	for(i = 0; i < k; ++i) {
		cin >> p1 >> p2 >> j;
		int x = nameMapping(p1), y = nameMapping(p2);
		road[x].emplace_back(make_pair(y, j));
		road[y].emplace_back(make_pair(x, j));
	}
	for(i = 1; i <= m; ++i) dijkstra(1000 + i);
	if(best_station == -1) printf("No Solution\n");
	else printf("G%d\n%.1lf %.1lf\n", best_station - 1000, best_min, best_avg + 0.001);
	return 0;
}
