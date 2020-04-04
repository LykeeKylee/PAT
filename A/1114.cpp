#include <bits/stdc++.h>
#define MAXSIZE 10001
using namespace std;
int person[MAXSIZE];
double estate[MAXSIZE], areas[MAXSIZE];
bool exist[MAXSIZE];
struct info {
	int id;
	int member;
	double m;
	double a;
};
map<int, info> allinfo;
int findsrc(int x) {
	int tmp = x;
	while(x != person[x]) x = person[x];
	while(tmp != person[tmp]) {
		int t = person[tmp];
		person[tmp] = x;
		tmp = t;
	}
	return x;
}
void union_(int x, int y) {
	int xsrc = findsrc(x), ysrc = findsrc(y);
//	printf("1 x=%04d: %04d %04d y=%04d: %04d %04d\n", x, xsrc, person[xsrc], y, ysrc, person[ysrc]);
	if(xsrc < ysrc) person[ysrc] = xsrc;
	else if(xsrc > ysrc) person[xsrc] = ysrc;
//	printf("2 x=%04d: %04d %04d y=%04d: %04d %04d\n", x, xsrc, person[xsrc], y, ysrc, person[ysrc]);
}
bool cmp(info &x, info &y) {
	if(x.a != y.a) return x.a > y.a;
	else return x.id < y.id;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < MAXSIZE; ++i) person[i] = i;
	for(i = 0; i < n; ++i) {
		int id, father, mother, k, child[5];
		double m, area;
		scanf("%d %d %d %d", &id, &father, &mother, &k);
		for(j = 0; j < k; ++j) {
			scanf("%d", child + j);
			union_(id, child[j]);
			exist[child[j]] = true;
		}
		scanf("%lf %lf", &m, &area);
		if(father != -1) {
			union_(id, father);
			exist[father] = true;
		}
		if(mother != -1) {
			union_(id, mother);
			exist[mother] = true;
		}
		exist[id] = true;
		estate[id] = m;
		areas[id] = area;
	}
	for(i = 0; i < MAXSIZE; ++i) {
		if(exist[i]) {
			int src = findsrc(i);
			allinfo[src].id = src;
			++allinfo[src].member;
			allinfo[src].m += estate[i];
			allinfo[src].a += areas[i];
		}
	}
	vector<info> collect;
	for(auto f = allinfo.begin(); f != allinfo.end(); ++f) {
		f->second.m /= f->second.member;
		f->second.a /= f->second.member;
		collect.emplace_back(f->second);
	}
	sort(collect.begin(), collect.end(), cmp);
	printf("%d", collect.size());
	for(auto c = collect.begin(); c != collect.end(); ++c) printf("\n%04d %d %0.3lf %0.3lf", c->id, c->member, c->m, c->a);
	return 0;
}
