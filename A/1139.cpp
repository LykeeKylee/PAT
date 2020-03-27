#include <bits/stdc++.h>
using namespace std;
bool relation[10002][10002];
map<int, vector<int>> sg;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}
int main() {
	int n, m, k, i, j, a, b;
	string sa, sb;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; ++i) {
		cin >> sa >> sb;
		a = stoi(sa, nullptr);
		b = stoi(sb, nullptr);
		if(sa.length() == sb.length()) {
			sg[a].emplace_back(b);
			sg[b].emplace_back(a);
		}
		relation[abs(a)][abs(b)] = relation[abs(b)][abs(a)] = true;
	}
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%d %d", &a, &b);
		vector<pair<int, int>> both;
		vector<int> af = sg[a], bf = sg[b];
		for(auto c = af.begin(); c != af.end(); ++c) {
			for(auto d = bf.begin(); d != bf.end(); ++d) {
				if(relation[abs(*c)][abs(*d)] && *c != b && *d != a) both.emplace_back(make_pair(abs(*c), abs(*d)));
			}
		}
		sort(both.begin(), both.end(), cmp);
		printf("%d\n", both.size());
		for(j = 0; j < both.size(); ++j) printf("%04d %04d\n", both[j].first, both[j].second);
	}
	return 0;
}
