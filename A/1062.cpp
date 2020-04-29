#include<bits/stdc++.h>
using namespace std;
struct person {
	int id, t, v, total;
};
bool cmp(person &a, person &b) {
	if(a.total != b.total) return a.total > b.total;
	else if(a.v != b.v) return a.v > b.v;
	else return a.id < b.id;
}
int main() {
	int n, l, h, i, j, id, t, v, cnt = 0;
	scanf("%d %d %d", &n, &l, &h);
	vector<person> ranks[4];
	for(i = 0; i < n; ++i) {
		scanf("%d %d %d", &id, &v, &t);
		person tmp{id, t, v, t + v};
		if(t < l || v < l) continue;
		else if(t < h && v < h && v >= t) ranks[2].emplace_back(tmp);
		else if(t < h && v >= h) ranks[1].emplace_back(tmp);
		else if(t >= h && v >= h) ranks[0].emplace_back(tmp);
		else ranks[3].emplace_back(tmp);
	}
	
	for(i = 0; i < 4; ++i) {
		sort(ranks[i].begin(), ranks[i].end(), cmp);
		cnt += ranks[i].size();
	}
	printf("%d\n", cnt);
	for(i = 0; i < 4; ++i) {
		for(j = 0; j < ranks[i].size(); ++j) printf("%08d %d %d\n", ranks[i][j].id, ranks[i][j].v, ranks[i][j].t);
	}
	return 0;
} 
