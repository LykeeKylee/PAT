#include<bits/stdc++.h>
using namespace std;
const int msize = 1050, inf = 999999999;
int n, m, k, ds, graph[msize][msize], minimumDist = -1, index = 0;
double avgDist = inf * 1.0;
bool visit[msize];
int encode(char x[]) {
	int id = 0;
	if(x[0] == 'G') {
		for(int i = 1; i < strlen(x); ++i)
			id = id * 10 + x[i] - '0';
		id += n;
	}
	else {
		for(int i = 0; i < strlen(x); ++i)
			id = id * 10 + x[i] - '0';
	}
	return id;
}
void dijkstra(int cand) {
	fill(visit, visit + msize, false);
	vector<int> dists(n + m + 1, inf);
	dists[cand] = 0;
	int remain = n + m, curDist = inf, cur;
	while(remain > 0) {
		curDist = inf;
		for(int i = 1; i <= n + m; ++i) {
			if(!visit[i] && dists[i] < curDist) {
				cur = i;
				curDist = dists[i];
			}
		}
		visit[cur] = true;
		remain--;
		
		for(int i = 1; i <= n + m; ++i) {
			if(!visit[i] && graph[cur][i] != inf) {
				if(curDist + graph[cur][i] < dists[i])
					dists[i] = curDist + graph[cur][i];
			}
		}
	}
//	for(int i = 1; i <= n; ++i) cout << dists[i] << ' ';
//	cout << endl; 
	int cnt = 0, minD = inf;
	for(int i = 1; i <= n; ++i) {
		if(dists[i] > ds) return;
		cnt += dists[i];
		minD = dists[i] < minD ? dists[i] : minD;
	}
	if(minD > minimumDist) {
		minimumDist = minD;
		avgDist = cnt * 1.0 / n;
		index = cand;
	}
	else if(minD == minimumDist) {
		if(cnt * 1.0 / n < avgDist) {
			avgDist = cnt * 1.0 / n;
			index = cand;
		}
		else if(cnt * 1.0 / n == avgDist) 
			index = cand;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	
	int i, j;
	scanf("%d %d %d %d", &n, &m, &k, &ds);
	fill(graph[0], graph[0] + msize * msize, inf);
	for(i = 0; i < k; ++i) {
		char p1[7], p2[7];
		int pp1, pp2, dist;
		scanf("%s %s %d", p1, p2, &dist);
		pp1 = encode(p1);
		pp2 = encode(p2);
		graph[pp1][pp2] = graph[pp2][pp1] = dist;
	}
//	for(i = 1; i <= n + m; ++i) {
//		for(j = 1; j <= n + m; ++j) 
//			printf("% 10d ", graph[i][j]);
//		cout << endl;
//	}
	for(i = n + 1; i <= n + m; ++i)
		dijkstra(i);
	if(!index)
		printf("No Solution\n");
	else
		printf("G%d\n%0.1f %0.1f", index - n, (double)minimumDist, avgDist + 0.005);
	return 0;
}
