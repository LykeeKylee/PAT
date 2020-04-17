#include<bits/stdc++.h>
using namespace std;
struct node{
	int s, x, y;
};
int slices[65][130][1290], dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}}, m, n, l, thresh;
bool visit[65][130][1290];
int bfs(int s, int x, int y) {
	int cnt = 0, i;
	node t{s, x, y};
	queue<node> q;
	q.push(t);
	visit[s][x][y] = true;
	while(!q.empty()) {
		node tn = q.front();
		q.pop();
		++cnt;
		for(int i = 0; i < 6; ++i) {
			int ns = tn.s + dir[i][0], nx = tn.x + dir[i][1], ny = tn.y + dir[i][2];
			if(ns >= 0 && ns < l && nx >= 0 && nx < m && ny >= 0 && ny < n && slices[ns][nx][ny] == 1 && !visit[ns][nx][ny]) {
				t = {ns, nx, ny};
				visit[ns][nx][ny] = true;
				q.push(t);
			}
		}
	}
	cnt = cnt >= thresh ? cnt : 0;
	return cnt;
}
int main() {
	int i, j, k, cnt = 0;
	scanf("%d %d %d %d", &m, &n, &l, &thresh);
	for(i = 0; i < l; ++i)
		for(j = 0; j < m; ++j)
			for(k = 0; k < n; ++k) scanf("%d", &slices[i][j][k]);
	for(i = 0; i < l; ++i) 
		for(j = 0; j < m; ++j)
			for(k = 0; k < n; ++k) {
				if(slices[i][j][k] == 1 && !visit[i][j][k]) cnt += bfs(i, j, k);
			}
	printf("%d\n", cnt);
	return 0;
}
