#include <bits/stdc++.h>
using namespace std;
struct score {
	string id;
	double sj=-1.0;
	double mid=-1.0;
	double fin=-1.0;
	double gfin=-1.0;
};
bool cmp(score &a, score &b) {
	if(a.gfin != b.gfin) return a.gfin > b.gfin;
	else return a.id < b.id;
}
int main() {
	int p, m, n, i, j;
	double s;
	string id;
	map<string, score> stu;
	map<string, int> q;
	vector<score> v;
	scanf("%d %d %d", &p, &m, &n);
	for(i = 0; i < p; ++i) {
		cin >> id;
		scanf("%lf", &s);
		if(s >= 200.0) {
			stu[id].id = id;
			stu[id].sj = s;
			q[id] = 1;
		}
	}
	for(i = 0; i < m; ++i) {
		cin >> id;
		scanf("%lf", &s);
		if(q[id] == 1) stu[id].mid = s;
	}
	for(i = 0; i < n; ++i) {
		cin >> id;
		scanf("%lf", &s);
		if(q[id] == 1) stu[id].fin = s;
	}
	for(auto k = stu.begin(); k != stu.end(); ++k) {
		if(k->second.mid <= k->second.fin) k->second.gfin = round(k->second.fin);
		else k->second.gfin = round(k->second.fin * 0.6 + k->second.mid * 0.4);
		if(k->second.gfin >= 60) v.emplace_back(k->second);
	}
	sort(v.begin(), v.end(), cmp);
	for(auto k = v.begin(); k != v.end(); ++k) {
		score t = *k;
		printf("%s %d %d %d %d\n", t.id.c_str(), int(t.sj), int(t.mid), int(t.fin), int(t.gfin));
	}
	return 0;
}
