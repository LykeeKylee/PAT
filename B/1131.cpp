#include<bits/stdc++.h>
using namespace std;
const int inf = 999999999;
int n, m, k, starting, ending, minCnt = inf, minTransfer = inf;
map<int, int> lineNo;
vector<int> lines[10005], trace, ans;
bool visit[10005];
int countTransfer() {
	int curLine = 0, cnt = -1;
	for(int i = 1; i < trace.size(); ++i) {
		if(curLine != lineNo[trace[i - 1] * 10000 + trace[i]]) 
			++cnt;
		curLine = lineNo[trace[i - 1] * 10000 + trace[i]];
	}
	return cnt;
}
void dfs(int root, int stationCnt) {
	if(root == ending) {
		if(stationCnt < minCnt) {
			minCnt = stationCnt;
			minTransfer = countTransfer();
			ans = trace;
		}
		else if(stationCnt == minCnt) {
			int transfer = countTransfer();
			if(transfer < minTransfer) {
				minTransfer = transfer;
				ans = trace;
			}
		}
		return;
	} 
	vector<int> *v = &lines[root];
	for(int i = 0; i < v->size(); ++i) {
		int to = (*v)[i];
		if(!visit[to]) {
			visit[to] = true;
			trace.push_back(to);
			dfs(to, stationCnt + 1);
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
	scanf("%d", &n);
	for(j = 0; j < n; ++j) {
		int pre, cur;
		scanf("%d %d", &m, &pre);
		for(i = 0; i < m - 1; ++i) {
			scanf("%d", &cur);
			lines[pre].push_back(cur);
			lines[cur].push_back(pre);
			lineNo[pre * 10000 + cur] = lineNo[cur * 10000 + pre] = j + 1;
			pre = cur;
		}
	}
	scanf("%d", &k);
	for(j = 0; j < k; ++j) {
		scanf("%d %d", &starting, &ending);
		fill(visit, visit + 10005, false);
		minCnt = minTransfer = inf;
		trace.clear();
		
		visit[starting] = true;
		trace.push_back(starting);
		dfs(starting, 0);
		printf("%d\n", minCnt);
		int from = starting, curLine = lineNo[from * 10000 + ans[1]];
		for(i = 1; i < ans.size(); ++i) {
			int tmpLine = lineNo[ans[i - 1] * 10000 + ans[i]];
			if(tmpLine != curLine) {
				printf("Take Line#%d from %04d to %04d.\n", curLine, from, ans[i - 1]);
				curLine = tmpLine;
				from = ans[i - 1]; 
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", curLine, from, ending);
	}
	return 0; 
}
