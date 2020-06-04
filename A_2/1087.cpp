#include<bits/stdc++.h>
using namespace std;
const int msize = 26 * 26 * 26 + 10, inf = 999999999;
int n, k, start, rome, happy[msize], max_happy = 0, routeCnt = 0, min_cost = inf;
double avg_happy = 0.0;
vector<pair<int, int>> graph[msize];
map<int, vector<int>> choice;
bool visit[msize];
set<int> remain;
vector<int> path, trace;
int encode(char x[]) {
	int id = 0;
	for(int i = 0; i < 3; ++i)
		id = id * 26 + x[i] - 'A';
	return id;
}
string decode(int id) {
	string name;
	for(int i = 0; i < 3; ++i) {
		name = char('A' + id % 26) + name;
		id /= 26;
	}
	return name;
}
void dijkstra() {
	int curCity, curDist = inf;
	vector<int> dist(msize, inf);
	fill(visit, visit + msize, false);
	dist[start] = 0;
	while(!remain.empty()) {
		curDist = inf;
		curCity = -1;
		for(auto s = remain.begin(); s != remain.end(); ++s) {
			if(!visit[*s] && dist[*s] < curDist) {
				curCity = *s;
				curDist = dist[*s];
			}
		}
		visit[curCity] = true;
		remain.erase(curCity);
		for(int i = 0; i < graph[curCity].size(); ++i) {
			int to = graph[curCity][i].first, len = graph[curCity][i].second;
			if(!visit[to]) {
				if(curDist + len < dist[to]) {
					dist[to] = curDist + len;
					choice[to].clear();
					choice[to].push_back(curCity);
				} else if(curDist + len == dist[to])
					choice[to].push_back(curCity);
			}
		}
	}
	min_cost = dist[rome];
}
void dfs(int root, int curHappy) {
	if(root == start) {
		routeCnt++;
		if(curHappy > max_happy) {
			max_happy = curHappy;
			path = trace;
			avg_happy = curHappy * 1.0 / (trace.size() - 1);
		} else if(curHappy == max_happy && avg_happy < curHappy * 1.0 / (trace.size() - 1)) {
			path = trace;
			avg_happy = curHappy * 1.0 / (trace.size() - 1);
		}
		return;
	}
	vector<int> *v = &choice[root];
	for(int i = 0; i < v->size(); ++i) {
		int to = (*v)[i];
		if(!visit[to]) {
			visit[to] = true;
			trace.push_back(to);
			dfs(to, curHappy + happy[to]);
			trace.pop_back();
			visit[to] = false;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif
	int i, j;
	char city1[5], city2[5], Rom[] = "ROM";
	scanf("%d %d %s", &n, &k, city1);
	start = encode(city1);
	rome = encode(Rom);
	remain.insert(start);
	for(i = 0; i < n - 1; ++i) {
		scanf("%s %d", city1, &j);
		happy[encode(city1)] = j;
		remain.insert(encode(city1));
	}
	for(i = 0; i < k; ++i) {
		int x, y;
		scanf("%s %s %d", city1, city2, &j);
		x = encode(city1);
		y = encode(city2);
		graph[x].push_back(make_pair(y, j));
		graph[y].push_back(make_pair(x, j));
	}
	dijkstra();
	fill(visit, visit + msize, false);
	trace.push_back(rome);
	visit[rome] = true;
	dfs(rome, happy[rome]);
	printf("%d %d %d %d\n", routeCnt, min_cost, max_happy, int(avg_happy));
	bool flag = true;
	for(auto v = path.rbegin(); v != path.rend(); ++v) {
		printf("%s%s", flag ? "" : "->", decode(*v).c_str());
		flag = false;
	}
	return 0;
}
