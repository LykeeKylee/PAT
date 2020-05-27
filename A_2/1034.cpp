#include<bits/stdc++.h>
using namespace std;
const int msize = 26 * 26 * 26 + 5;
int gang[msize], weight[msize], gangweight[msize];
int getid(string &s) {
	int id = 0, flag = 1;
	for(int i = s.length() - 1; i >= 0; --i) {
		id += (s[i] - 'A') * flag;
		flag *= 26;
	}
	return id;
}
string getname(int id) {
	string name;
	int flag = pow(26,2);
	while(flag > 0) {
		name += ((id / flag) + 'A');
		id %= flag;
		flag /= 26;
	}
	return name;
}
int finds(int x) {
	int y = x, tmp;
	while(x != gang[x]) x = gang[x];
	while(y != gang[y]) {
		tmp = gang[y];
		gang[y] = x;
		y = gang[tmp];
	}
	return x;
}
void unionize(int x, int y) {
	int xs = finds(x), ys = finds(y);
	if(xs != ys) {
		gangweight[xs] += gangweight[ys];
		gang[ys] = xs;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, k, i, j;
	string name1, name2;
	scanf("%d %d", &n, &k);
	for(i = 0; i < msize; ++i) gang[i] = i;
	set<int> list;
	for(i = 0; i < n; ++i) {
		cin >> name1 >> name2;
		scanf("%d", &j);
		int id1 = getid(name1), id2 = getid(name2);
		weight[id1] += j;
		weight[id2] += j;
		unionize(id1, id2);
		gangweight[finds(id1)] += j;
		list.insert(id1);
		list.insert(id2);
	}
	set<int> heads;
	map<int, int> size;
	map<int, vector<int>> cluster;
	for(auto s = list.begin(); s != list.end(); ++s) {
		int head = finds(*s);
		size[head]++;
		heads.insert(head);
		cluster[head].emplace_back(*s);
	}
	vector<pair<int, int>> ans;
	for(auto s = heads.begin(); s != heads.end(); ++s) {
		if(size[*s] > 2 && gangweight[*s] > k) {
			int head = *s;
			for(i = 0; i < cluster[*s].size(); ++i) head = weight[head] > weight[cluster[*s][i]] ? head:cluster[*s][i];
			ans.emplace_back(make_pair(head, size[*s]));
		}
	}
	printf("%d\n", ans.size());
	for(i = 0; i < ans.size(); ++i) printf("%s %d\n", getname(ans[i].first).c_str(), ans[i].second);
	return 0;
}
