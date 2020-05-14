#include<bits/stdc++.h>
using namespace std;
map<string, double> happy;
map<string, map<string, int>> route;
map<string, bool> visit;
double happy_cnt, avg_happy;
int min_cost = 999999999;
map<int, int> cost_cnt;
vector<string> trace;
void dfs(string start, double cur_happy, int cur_cost, vector<string> cur_trace, string terminal) {
	if(start == terminal) {
		int len = cur_trace.size() - 1;
		++cost_cnt[cur_cost];
		if(cur_cost < min_cost) {
			min_cost = cur_cost;
			happy_cnt = cur_happy;
			avg_happy = cur_happy / len;
			trace = cur_trace;
		} else if(cur_cost == min_cost && cur_happy > happy_cnt) {
			happy_cnt = cur_happy;
			avg_happy = cur_happy / len;
			trace = cur_trace;
		}
		else if(cur_cost == min_cost && cur_happy == happy_cnt && cur_happy / len > avg_happy) {
			avg_happy = cur_happy / len;
			trace = cur_trace;
		}
		return;
	}
	map<string, int> *cur_route = &route[start];
	for(auto r = (*cur_route).begin(); r != (*cur_route).end(); ++r) {
		string next_city = r->first;
		if(!visit[next_city] && cur_cost + r->second <= min_cost) {
			visit[start] = true;
			cur_trace.emplace_back(next_city);
			dfs(next_city, cur_happy + happy[next_city], cur_cost + r->second, cur_trace, terminal);
			visit[next_city] = false;
			cur_trace.pop_back();
		}
	}
}
int main() {
	int n, k, i, j;
	string city1, city2, start;
	scanf("%d %d", &n, &k);
	cin >> start;
	visit[start] = false;
	for(i = 0; i < n - 1; ++i) {
		cin >> city1;
		scanf("%d", &j);
		happy[city1] = j;
		visit[city1] = false;
	}
	for(i = 0; i < k; ++i) {
		cin >> city1 >> city2;
		scanf("%d", &j);
		route[city1][city2] = j;
		route[city2][city1] = j;
	}
	vector<string> cur_trace;
	cur_trace.emplace_back(start);
	visit[start] = true;
	dfs(start, 0, 0, cur_trace, "ROM");
	printf("%d %d %d %d\n", cost_cnt[min_cost], min_cost, int(happy_cnt), int(happy_cnt / (trace.size() - 1)));
	for(i = 0; i < trace.size(); ++i) printf("%s%s", trace[i].c_str(), (i == trace.size() - 1 ? "\n":"->"));
	return 0;
}

