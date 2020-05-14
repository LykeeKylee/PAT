#include<bits/stdc++.h>
using namespace std;
struct graduate {
	double ge, gi, gf;
	int id, rank;
	vector<int> choice;
};
bool cmp(graduate &a, graduate &b) {
	if(a.gf != b.gf) return a.gf > b.gf;
	else return a.ge > b.ge;
}
vector<graduate> app;
int quota[102], min_rank[102] = {0};
vector<int> admission[102];
int main() {
	int n, m, k, i, j;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 0; i < m; ++i) {
		scanf("%d", quota + i);
		min_rank[i] = 999999999;
	}
	for(i = 0; i < n; ++i) {
		graduate g;
		g.id = i;
		scanf("%lf %lf", &g.ge, &g.gi);
		g.gf = (g.ge + g.gi) / 2.0;
		g.choice.resize(k);
		for(j = 0; j < k; ++j) scanf("%d", &g.choice[j]);
		app.emplace_back(g);
	}
	sort(app.begin(), app.end(), cmp);
	int pre_rank = 1;
	app[0].rank = pre_rank;
	for(i = 1; i < n; ++i) {
		if(app[i].gf == app[i - 1].gf && app[i].ge == app[i-1].ge) app[i].rank = pre_rank;
		else {
			app[i].rank = pre_rank + 1;
			++pre_rank;
		}
	}
	for(i = 0; i < n; ++i) {
		for(j = 0; j < k; ++j) {
			if(quota[app[i].choice[j]] > 0 || min_rank[app[i].choice[j]] == app[i].rank) {
				--quota[app[i].choice[j]];
				admission[app[i].choice[j]].emplace_back(app[i].id);
				min_rank[app[i].choice[j]] = app[i].rank;
				break;
			}
		}
	} 
	for(i = 0; i < m; ++i) {
		sort(admission[i].begin(), admission[i].end());
		for(j = 0; j < admission[i].size(); ++j) printf("%s%d", j == 0 ? "" : " ", admission[i][j]);
		printf("\n");
	}
	return 0;
} 
