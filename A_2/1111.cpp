#include<bits/stdc++.h>
using namespace std;
const int inf = 999999999;
int n, m, length[505][505], times[505][505], start, ending, minL = inf, minT = inf, minTime = inf, minNode = inf;
bool visit[505];
unordered_map<int, vector<int>> lenRec, timeRec;
vector<int> path1, path2, trace;
void dijkstra(int mode) {
	int curNode = -1, curNum = inf, remain = n;
	vector<int> nums(n, inf);
	fill(visit, visit + 505, false);
	nums[start] = 0;
	while(remain > 0) {
		curNum = inf;
		for(int i = 0; i < n; ++i) {
			if(!visit[i] && nums[i] < curNum) {
				curNum = nums[i];
				curNode = i;
			}
		}
		visit[curNode] = true;
		remain--;
		for(int i = 0; i < n; ++i) {
			if(!visit[i]) {
				if(mode == 0) {
					if(curNum + length[curNode][i] < nums[i]) {
						nums[i] = curNum + length[curNode][i];
						lenRec[i].clear();
						lenRec[i].push_back(curNode);
					} else if(curNum + length[curNode][i] == nums[i])
						lenRec[i].push_back(curNode);
				} else {
					if(curNum + times[curNode][i] < nums[i]) {
						nums[i] = curNum + times[curNode][i];
						timeRec[i].clear();
						timeRec[i].push_back(curNode);
					} else if(curNum + times[curNode][i] == nums[i])
						timeRec[i].push_back(curNode);
				}
			}
		}
	}
	if(mode == 0)
		minL = nums[ending];
	else
		minT = nums[ending];
}
void dfs(int root, int cnt, int mode) {
	if(root == start) {
		if(mode == 0 && cnt < minTime) {
			path1 = trace;
			minTime = cnt;
		} else if(mode == 1 && cnt < minNode) {
			path2 = trace;
			minNode = cnt;
		}
		return;
	}
	vector<int> *v;
	if(mode == 0) v = &lenRec[root];
	else v = &timeRec[root];
	for(int i = 0; i < v->size(); ++i) {
		int to = (*v)[i];
		if(!visit[to]) {
			visit[to] = true;
			trace.push_back(to);
			if(mode == 0)
				dfs(to, cnt + times[to][root], mode);
			else
				dfs(to, cnt + 1, mode);
			visit[to] = false;
			trace.pop_back();
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &n, &m);
	fill(length[0], length[0] + 505 * 505, inf);
	fill(times[0], times[0] + 505 * 505, inf);
	for(i = 0; i < m; ++i) {
		int v1, v2, one_way, l, t;
		scanf("%d %d %d %d %d", &v1, &v2, &one_way, &l, &t);
		length[v1][v2] = l;
		times[v1][v2] = t;
		if(!one_way) {
			length[v2][v1] = l;
			times[v2][v1] = t;
		}
	}
	scanf("%d %d", &start, &ending);
	dijkstra(0);
	dijkstra(1);
	fill(visit, visit + 505, false);
	visit[ending] = true;
	trace.push_back(ending);
	dfs(ending, 0, 0);
	fill(visit, visit + 505, false);
	visit[ending] = true;
	trace.clear();
	trace.push_back(ending);
	dfs(ending, 0, 1);
	bool flag = true;
	if(path1.size() != path2.size())
		flag = false;
	else {
		for(i = 0; i < path1.size(); ++i) {
			if(path1[i] != path2[i]) {
				flag = false;
				break;
			}
		}
	}
	if(flag) {
		printf("Distance = %d; Time = %d:", minL, minT);
		for(i = path1.size() - 1; i >= 0; --i)
			printf("%s%d", i == path1.size() - 1 ? " " : " -> ", path1[i]);
	} else {
		printf("Distance = %d:", minL);
		for(i = path1.size() - 1; i >= 0; --i)
			printf("%s%d", i == path1.size() - 1 ? " " : " -> ", path1[i]);
		printf("\n");
		printf("Time = %d:", minT);
		for(i = path2.size() - 1; i >= 0; --i)
			printf("%s%d", i == path2.size() - 1 ? " " : " -> ", path2[i]);
	}
	return 0;
}
