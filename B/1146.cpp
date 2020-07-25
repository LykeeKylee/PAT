#include<bits/stdc++.h>
using namespace std;
int n, m, k, edge[1005][1005], degree[1005], test[1005];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		edge[x][y] = 1;
		degree[y] += 1;
	}
	vector<int> ans;
	scanf("%d", &k);
//	for(i = 1; i <= n; ++i) cout << degree[i] << endl;
	for(j = 0; j < k; ++j) {
		vector<int> tmp(degree, degree + 1005);
		for(i = 1; i <= n; ++i) scanf("%d", test + i);
		bool flag = true;
		for(i = 1; i <= n && flag; ++i) {
			if(tmp[test[i]] == 0) {
				for(int e = 1; e <= n; ++e) {
					if(edge[test[i]][e] == 1)
						tmp[e]--;
				}
			}
			else if(tmp[test[i]] > 0) flag = false;
		}
		if(!flag) ans.push_back(j);
	}
	for(i = 0; i < ans.size(); ++i) {
		printf("%d%s", ans[i], i == ans.size() - 1 ? "":" ");
	}
	return 0;
} 
