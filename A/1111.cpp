#include<bits/stdc++.h>
using namespace std;
const int inf = 999999999;
int ret1, ret2;
map<int, map<int, int>> length, cost;
vector<int> path1, path2;
vector<int> dijkstra(int v1, int v2, int type, int n) {
	// 是否被访问
	vector<bool> visit(n, false);
	// 站点或时间的记录    当前距离或者时间
	vector<int> cnt(n, 0), dist(n, inf);
	// 路径记录
	map<int, vector<int>> path;
	int n_ = n;
	dist[v1] = 0;
	while(--n_ > 0) {
		int cursec = inf, mindist = inf, cnt_ = inf;
		for(int i = 0; i < n; ++i) {
			if(!visit[i]) {
				if(dist[i] < mindist) {
					cursec = i;
					mindist = dist[i];
					cnt_ = cnt[i];
				}
			}
		}
		visit[cursec] = true;
		map<int, int> *link = (type == 1 ? &length[cursec] : &cost[cursec]);
		for(auto i = link->begin(); i != link->end(); ++i) {
			if(!visit[i->first]) {
				if(mindist + i->second < dist[i->first] || (mindist + i->second == dist[i->first] && cnt_ + (type == 1 ? cost[cursec][i->first] : 1) < cnt[i->first])) {
					dist[i->first] = mindist + i->second;
					path[i->first] = path[cursec];
					path[i->first].emplace_back(cursec);
					cnt[i->first] = cnt[cursec];
					cnt[i->first] += (type == 1 ? cost[cursec][i->first] : 1);
				}
			}
		}
	}
	if(type == 1) ret1 = dist[v2];
	else ret2 = dist[v2];
	path[v2].emplace_back(v2);
	return path[v2];
}
int main() {
	int n, m, i, j, v1, v2, one, l, t;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; ++i) {
		scanf("%d %d %d %d %d", &v1, &v2, &one, &l, &t);
		length[v1][v2] = l;
		cost[v1][v2] = t;
		if(!one) {
			length[v2][v1] = l;
			cost[v2][v1] = t;
		}
	}
	scanf("%d %d", &v1, &v2);
	bool same = true;
	path1 = dijkstra(v1, v2, 1, n);
	path2 = dijkstra(v1, v2, 2, n);
	if(path1.size() != path2.size()) same = false;
	else {
		for(i = 0; i < path1.size(); ++i) {
			if(path1[i] != path2[i]) {
				same = false;
				break;
			}
		}
	}
	if(same) {
		printf("Distance = %d; Time = %d:", ret1, ret2);
		for(i = 0; i < path1.size(); ++i) printf("%s%d", (i == 0) ? " " : " -> ", path1[i]);
	}
	else {
		printf("Distance = %d:", ret1);
		for(i = 0; i < path1.size(); ++i) printf("%s%d", (i == 0) ? " " : " -> ", path1[i]);
		cout << endl;
		printf("Time = %d:", ret2);
		for(i = 0; i < path2.size(); ++i) printf("%s%d", (i == 0) ? " " : " -> ", path2[i]);
	}
	return 0;
}
