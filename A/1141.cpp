#include <bits/stdc++.h>
using namespace std;
struct school {
	string name;
	int total;
	int cnt;
};
bool cmp(school &a, school &b) {
	if(a.total != b.total) return a.total > b.total;
	else if(a.cnt != b.cnt) return a.cnt < b.cnt;
	else return a.name < b.name;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	map<string, school> schoolmap;
	map<string, double> totalsc;
	vector<school> ranks;
	for(i = 0; i < n; ++i) {
		string id, scl;
		double sc;
		cin >> id;
		scanf("%lf", &sc);
		cin >> scl;
		transform(scl.begin(), scl.end(), scl.begin(), ::tolower);
		schoolmap[scl].name = scl;
		if(id[0] == 'T') totalsc[scl] += (1.5 * sc);
		else if(id[0] == 'A') totalsc[scl] += sc;
		else totalsc[scl] += (sc / 1.5);
		schoolmap[scl].cnt++;
	}
	for(auto s = schoolmap.begin(); s != schoolmap.end(); ++s) {
		s->second.total = int(totalsc[s->second.name]);
		ranks.emplace_back(s->second);
	}
	sort(ranks.begin(), ranks.end(), cmp);
	int r = 0, offset = 1, cur = ranks[i].total - 1;
	cout << schoolmap.size() << endl;
	for(i = 0; i < ranks.size(); ++i) {
		if(ranks[i].total == cur) {
			offset++;
		}
		else {
			r += offset;
			offset = 1;
			cur = ranks[i].total;
		}
		printf("%d %s %d %d\n", r, ranks[i].name.c_str(), int(ranks[i].total), ranks[i].cnt);
	}
	return 0;
}
