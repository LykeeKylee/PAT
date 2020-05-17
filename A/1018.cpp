#include<bits/stdc++.h>
using namespace std;
const int inf = 999999999;
int bike[505], c, n, s, m, hc, min_weight = inf, min_send = inf, min_take_back = inf;
vector<int> trace, min_trace;
bool visit[505];
vector<pair<int, int>> edge[505];
void dfs(int root, int weight, int curbike, int send) {
	if(root == s) {
		if(weight < min_weight) {
			min_weight = weight;
			min_send = send;
			min_take_back = curbike;
			min_trace = trace;
		} else if(weight == min_weight) {
			if(send < min_send || (send == min_send && curbike < min_take_back)) {
				min_weight = weight;
				min_send = send;
				min_take_back = curbike;
				min_trace = trace;
			}
		}
		return;
	}
	vector<pair<int, int>> *v = &edge[root];
	for(int i = 0; i < v->size(); ++i) {
		int t, w, dsend = 0, dbike = 0;
		t = (*v)[i].first;
		w = (*v)[i].second;
		if(bike[t] < hc) {
			if(curbike < hc - bike[t]) {
				dsend = hc - bike[t] - curbike;
				dbike = -curbike;
			}
			else dbike = bike[t] - hc;
		} else if(bike[t] > hc) dbike = bike[t] - hc;
		if(!visit[t]) {
			visit[t] = true;
			trace.emplace_back(t);
			dfs(t, weight + w, curbike + dbike, send + dsend);
			trace.pop_back();
			visit[t] = false;
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	scanf("%d %d %d %d", &c, &n, &s, &m);
	hc = c / 2;
	for(int i = 1; i <= n; ++i) scanf("%d", bike + i);
	for(int i = 0; i < m; ++i) {
		int si, sj, tij;
		scanf("%d %d %d", &si, &sj, &tij);
		edge[si].emplace_back(make_pair(sj, tij));
		edge[sj].emplace_back(make_pair(si, tij));
	}
	fill(visit, visit + 505, false);
	visit[0] = true;
	trace.emplace_back(0);
	dfs(0, 0, 0, 0);
	printf("%d", min_send);
	for(int i = 0; i < min_trace.size(); ++i) printf("%s%d", i == 0 ? " ":"->", min_trace[i]);
	printf(" %d\n", min_take_back);
	return 0;
}
