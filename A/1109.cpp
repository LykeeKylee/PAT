#include<bits/stdc++.h>
using namespace std;
struct person {
	string name;
	int height;
};
bool cmp(person &a, person &b) {
	if(a.height != b.height) return a.height > b.height;
	else return a.name < b.name;
}
int main() {
	int n, k, m, i, j, col, start;
	scanf("%d %d", &n, &k);
	vector<person> q;
	for(i = 0; i < n; ++i) {
		person t;
		cin >> t.name >> t.height;
		q.emplace_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	m = n / k;
	start = 0;
	for(i = 0; i < k; ++i) {
		col = (i == 0 ? m + n % m : m);
		int mid = col / 2 + 1, pos = col / 2 + 1, flag = -1, cnt = 1;
		vector<string> rank(col + 1);
		for(j = start; j < start + col; ++j) {
			rank[pos] = q[j].name;
			pos = mid + flag * cnt;
			flag *= -1;
			if(flag == -1) ++cnt;
		}
		for(j = 1; j < rank.size(); ++j) printf("%s%s", rank[j].c_str(), j == rank.size() - 1 ? "\n" : " ");
		start += col;
	}
	return 0;
}
