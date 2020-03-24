#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k, i, j, from, to, cities, start, end;
	int graphs[300][300], id, length = 99999999;
	string tsc = "TS simple cycle", tc = "TS cycle", ntc = "Not a TS cycle";
	cin >> n >> m;
	for(i = 0; i < m; ++i) {
		int v1, v2, d;
		scanf("%d %d %d", &v1, &v2, &d);
		graphs[v1][v2] = graphs[v2][v1] = d;
	}
	cin >> k;
	for(i = 1; i <= k; ++i) {
		int total = 0, block = 0;
		map<int, int> visit;
		cin >> cities;
		for(j = 0; j < cities; ++j) {
			if(j == 0) {
				cin >> from;
				start = from;
				visit[from] = 1;
			} else {
				cin >> to;
				if(graphs[from][to] != 0) total += graphs[from][to];
				else block = 1;
				visit[to] = 1;
				from = to;
				if(j == cities - 1) end = to;
			}
		}
		if(block == 1) printf("Path %d: %s (%s)\n", i, "NA", ntc.c_str());
		else {
			if(start != end) printf("Path %d: %d (%s)\n", i, total, ntc.c_str());
			else {
				if(visit.size() != n)  printf("Path %d: %d (%s)\n", i, total, ntc.c_str());
				else if(cities != n + 1) {
					printf("Path %d: %d (%s)\n", i, total, tc.c_str());
					if(total < length) {
						length = total;
						id = i;
					}
				} else {
					printf("Path %d: %d (%s)\n", i, total, tsc.c_str());
					if(total < length) {
						length = total;
						id = i;
					}
				}
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", id, length);
	return 0;
}
