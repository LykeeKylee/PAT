#include<bits/stdc++.h>
using namespace std;
struct info {
	int dst, cost;
};
const int inf = 999999999;
int n, m, s, d, x, y, min_dst = inf, min_cost = inf;
vector<pair<int, info>> path[505];
vector<int> trace, trace_ans;
bool visit[505];
void dfs(int root, int dst, int cost) {
	if(root == d) {
		if(dst < min_dst || (dst == min_dst && cost < min_cost)) {
			min_dst = dst;
			trace_ans = trace;
			min_cost = cost;
		}
		return;
	}
	vector<pair<int, info>> *v = &path[root];
	for(int i = 0; i < v->size(); ++i) {
		int des = (*v)[i].first, d = (*v)[i].second.dst, c = (*v)[i].second.cost;
		if(!visit[des]) {
			trace.emplace_back(des);
			visit[des] = true;
			dfs(des, dst + d, cost + c);
			visit[des] = false;
			trace.pop_back();
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	
	scanf("%d %d %d %d", &n, &m, &s, &d);
	for(int i = 0; i < m; ++i) {
		info tmp;
		scanf("%d %d %d %d", &x, &y, &tmp.dst, &tmp.cost);
		path[x].emplace_back(make_pair(y, tmp));
		path[y].emplace_back(make_pair(x, tmp));
	}
	visit[s] = true;
	trace.emplace_back(s);
	dfs(s, 0, 0);
	for(int i = 0; i < trace_ans.size(); ++i) printf("%d ", trace_ans[i]);
	printf("%d %d\n", min_dst, min_cost);
	return 0;
}
