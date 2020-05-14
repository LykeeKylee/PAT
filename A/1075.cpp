#include<bits/stdc++.h>
using namespace std;
struct player {
	int id, rank, full_mark, perfect = 0;
	int part_mark[6] = {-2, -2, -2, -2, -2, -2};
};
int mark[6];
bool cmp(player &a, player &b) {
	if(a.full_mark != b.full_mark) return a.full_mark > b.full_mark;
	else if(a.perfect != b.perfect) return a.perfect > b.perfect;
	else return a.id < b.id;
}
int main() {
	int n, k, m, i, j, id, g;
	scanf("%d %d %d", &n, &k, &m);
	vector<player> pta(n + 2), final;
	for(i = 1; i <= k; ++i) scanf("%d", mark + i);
	for(i = 1; i <= m; ++i) {
		scanf("%d %d %d", &id, &j, &g);
		pta[id].id = id;
		pta[id].part_mark[j] = max(g, pta[id].part_mark[j]);
	}
	for(i = 1; i <= n; ++i) {
		g = 0;
		for(j = 1; j <= k; ++j) {
			if(pta[i].part_mark[j] < 0) ++g;
			pta[i].full_mark += max(0, pta[i].part_mark[j]);
			if(pta[i].part_mark[j] == mark[j]) ++pta[i].perfect;
		}
		if(g != k) final.emplace_back(pta[i]);
	}
	sort(final.begin(), final.end(), cmp);
	int rank = 0, offset = 1;
	g = final[0].full_mark - 1;
	for(i = 0; i < final.size(); ++i) {
		if(final[i].full_mark != g) {
			rank += offset;
			offset = 1;
		}
		else ++offset;
		g = final[i].full_mark;
		printf("%d %05d %d", rank, final[i].id, final[i].full_mark);
		for(j = 1; j <= k; ++j) {
			if(final[i].part_mark[j] == -2) printf(" -");
			else if(final[i].part_mark[j] == -1) printf(" 0");
			else printf(" %d", final[i].part_mark[j]);
		}
		printf("\n");
	}
	return 0;
} 
