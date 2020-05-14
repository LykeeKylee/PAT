#include <bits/stdc++.h>
using namespace std;
int indegree[10005], intmp[10005], query[10005];
int main() {
	int n, m, k, i, j, x;
	scanf("%d %d", &n, &m);
	vector<int> error;
	map<int, vector<int> > graphs;
	fill(indegree, indegree + 10005, 0);
	for(i = 0; i < m; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		graphs[from].push_back(to);
		++indegree[to];
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		copy(indegree, indegree + n + 1, intmp);
		for(j = 0; j < n; ++j) scanf("%d", &query[j]);
		for(j = 0; j < n; ++j) {
			x = query[j];
			if(intmp[x] != 0 || intmp[x] == -1) {
				error.push_back(i);
				break;
			} else {
				intmp[x] = -1;
				vector<int> *ptr = &graphs[x];
				for(vector<int>::iterator it = ptr->begin(); it != ptr->end(); ++it) {
					--intmp[*it];
				}
			}
		}
	}
	for(i = 0; i < error.size(); ++i) printf("%s%d", (i == 0 ? "" : " "), error[i]);
	return 0;
}
