#include<bits/stdc++.h>
using namespace std;
const int msize = 505, inf = 999999999;
int n, m, c1, c2, team[msize], graph[msize][msize];
bool v[msize];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif

	int i, j;
	set<int> nvisit;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for(i = 0; i < n; ++i) {
		scanf("%d", team + i);
		nvisit.insert(i);
	}
	fill(graph[0], graph[0] + msize * msize, inf);
	for(i = 0; i < m; ++i) {
		int x, y, l;
		scanf("%d %d %d", &x, &y, &l);
		graph[x][y] = graph[y][x] = l;
	}

	vector<int> lCnt(n + 1, inf), teamCnt(n + 1, 0), lNum(n + 1, 0);
	fill(v, v + msize, false);
	int sCnt = 0, cLen = inf, cTeam = 0, cc;
	lCnt[c1] = 0;
	teamCnt[c1] = team[c1];
	lNum[c1] = 1;
	while(!nvisit.empty()) {
		cLen = inf;
		for(auto s = nvisit.begin(); s != nvisit.end(); ++s) {
			if(lCnt[*s] < cLen) {
				cc = *s;
				cLen = lCnt[*s];
				cTeam = teamCnt[*s];
			}
		}
		v[cc] = true;
		nvisit.erase(cc);

		for(i = 0; i < n; ++i) {
			if(!v[i] && graph[cc][i] != inf) {
				if(lCnt[i] == cLen + graph[cc][i]) {
					lNum[i] += lNum[cc];
					teamCnt[i] = teamCnt[i] < (cTeam + team[i]) ? (cTeam + team[i]) : teamCnt[i];
				} else if(lCnt[i] > cLen + graph[cc][i]) {
					lNum[i] = lNum[cc];
					teamCnt[i] = cTeam + team[i];
					lCnt[i] = cLen + graph[cc][i];
				}
			}
		}
	}
	printf("%d %d\n", lNum[c2], teamCnt[c2]);
	return 0;
}
