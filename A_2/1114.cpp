#include<bits/stdc++.h>
using namespace std;
int person[10005];
double totalm[10005], totalarea[10005];
bool visit[10005];
struct family_info {
	int id, size;
	double m, area;
};
bool cmp(family_info &a, family_info &b) {
	if(a.area != b.area) return a.area > b.area;
	else return a.id < b.id;
}
int find_src(int x) {
	int y = x, tmp;
	while(x != person[x]) x = person[x];
	while(y != person[y]) {
		tmp = person[y];
		person[y] = x;
		y = person[tmp];
	}
	return x;
}
void unionize(int x, int y) {
	int xs = find_src(x), ys = find_src(y);
	if(xs < ys) person[ys] = xs;
	else person[xs] = ys; 
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, id, father, mother, k, child, i, j;
	double m, area;
	scanf("%d", &n);
	for(i = 0; i < 10005; ++i) person[i] = i;
	for(i = 0; i < n; ++i) {
		scanf("%d %d %d", &id, &father, &mother);
		if(father != -1) unionize(id, father);
		if(mother != -1) unionize(id, mother);
		visit[id] = visit[father] = visit[mother] = true;
		scanf("%d", &k);
		for(j = 0; j < k; ++j) {
			scanf("%d", &child);
			unionize(id, child);
			visit[child] = true;
		}
		scanf("%lf %lf", &m, &area);
		totalm[id] += m;
		totalarea[id] += area;
	}
	set<int> family;
	map<int, int> cnt;
	map<int, double> mans, areans;
	for(i = 0; i < 10005; ++i) {
		if(visit[i]) {
			int src = find_src(i);
			family.insert(src);
			cnt[src]++;
			mans[src] += totalm[i];
			areans[src] += totalarea[i];
		}
	}
	vector<family_info> ans;
	for(auto s = family.begin(); s != family.end(); ++s) {
		family_info tmp = {*s, cnt[*s], mans[*s] / cnt[*s], areans[*s] / cnt[*s]};
		ans.emplace_back(tmp);
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for(i = 0; i < ans.size(); ++i) printf("%04d %d %0.3lf %0.3lf\n", ans[i].id, ans[i].size, ans[i].m, ans[i].area);
	return 0; 
}
