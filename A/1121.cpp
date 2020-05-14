#include <bits/stdc++.h>
using namespace std;
map<int, string> couple;
map<int, int> pos;
int guests[10002];
vector<int> single;
int main() {
	int n, m, x, y, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		couple[x] = to_string(y);
		couple[y] = to_string(x);
	}
	scanf("%d", &m);
	for(i = 0; i < m; ++i) {
		scanf("%d", guests + i);
		pos[guests[i]] = i + 1;
	}
	for(i = 0; i < m; ++i) {
		if(couple[guests[i]] == "") single.push_back(guests[i]);
		else {
			if(pos[atoi(couple[guests[i]].c_str())] == 0) single.push_back(guests[i]);
		}
	}
	sort(single.begin(), single.end());
	cout << single.size() << endl;
	for(auto s = single.begin(); s != single.end(); ++s) printf("%s%05d", (s == single.begin() ? "" : " "), *s);
	return 0;
}
