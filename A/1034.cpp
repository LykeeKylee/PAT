#include<bits/stdc++.h>
using namespace std;
const int size = 26 * 26 * 26 + 5;
struct info {
	string head;
	int size;
};
// each memeber's weight, source and the gang's total weight
int weight[size], src[size], gangweight[size];
// the gangs' lists
vector<int> ganglist[size];
bool cmp(info &a, info &b) { return a.head < b.head; }
// map a name to the id
int gid(char name[]) {
	int id = 0, flag = 1;
	for(int i = strlen(name) - 1; i >= 0; --i) {
		id += (int(name[i] - 'A') * flag);
		flag *= 26;
	}
	return id;
}
// map an id to the name
string gname(int id) {
	int flag = 26 * 26;
	string name;
	for(int i = 0; i < 3; ++i) {
		name += char('A' + id / flag);
		id %= flag;
		flag /= 26;
	}
	return name;
}
int find_src(int x) {
	int y = x, tmp;
	while(x != src[x]) x = src[x];
	while(y != src[y]) {
		tmp = src[y];
		src[y] = x;
		y = src[tmp];
	}
	return x;
}
void union_find(int x, int y) {
	int x_src = find_src(x), y_src = find_src(y);
	if(x_src != y_src) {
		src[y_src] = x_src;
		gangweight[x_src] += gangweight[y_src];
	}
}
int main() {
	int n, k, i, j, id1, id2;
	char n1[4], n2[4];
	// all people, possible gangs
	set<int> people, gangs;
	for(i = 0; i < size; ++i) src[i] = i;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; ++i) {
		scanf("%s %s %d", n1, n2, &j);
		id1 = gid(n1), id2 = gid(n2);
		weight[id1] += j;
		weight[id2] += j;
		union_find(id1, id2);
		people.insert(id1);
		people.insert(id2);
		gangweight[find_src(id1)] += j;
	}
	for(auto s = people.begin(); s != people.end(); ++s) {
		int src = find_src(*s);
		if(gangs.find(src) == gangs.end()) gangs.insert(src);
		ganglist[src].emplace_back(*s);
	}
	vector<info> ans;
	for(auto s = gangs.begin(); s != gangs.end(); ++s) {
		if(gangweight[*s] > k && ganglist[*s].size() > 2) {
			int mid = -1, mw = -1;
			// find the head in the gang
			for(i = 0; i < ganglist[*s].size(); ++i) {
				if(weight[ganglist[*s][i]] > mw) {
					mid = ganglist[*s][i];
					mw = weight[ganglist[*s][i]];
				}
			}
			info tmp{gname(mid), ganglist[*s].size()};
			ans.emplace_back(tmp);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size()); 
	for(i = 0; i < ans.size(); ++i) printf("%s %d\n", ans[i].head.c_str(), ans[i].size);
	return 0;
}
