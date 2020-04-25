#include<bits/stdc++.h>
using namespace std;
vector<int> user[1002];
bool visit[1002];
int levelcnt[1002];
int bfs(int root, int l) {
	queue<int> q;
	int cnt = 0;
	q.push(root);
	visit[root] = true;
	levelcnt[root] = 0;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int i = 0; i < user[front].size(); ++i) {
			/* Firstly check the follower whether he has been visited 
			and then update the level. Otherwise some levels may be covered by new levels when there is a circuit.*/
			if(!visit[user[front][i]]) {
				visit[user[front][i]] = true;
				levelcnt[user[front][i]] = levelcnt[front] + 1;
				if(levelcnt[user[front][i]] > l) break;
				q.push(user[front][i]);
				++cnt;
			}
		}
	}
	return cnt;
}
int main() {
	int n, l, k, i, j, x;
	scanf("%d %d", &n, &l);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for(j = 1; j <= k; ++j) {
			scanf("%d", &x);
			user[x].emplace_back(i);
		}
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%d", &x);
		fill(visit, visit + 1002, false);
		fill(levelcnt, levelcnt + 1002, 0);
		int cnt = bfs(x, l);
		printf("%d\n", cnt);
	}
	return 0;
}
