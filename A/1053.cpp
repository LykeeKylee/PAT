#include<bits/stdc++.h>
using namespace std;
struct node {
	int w;
	vector<int> child;
};
node forest[101];
vector<int> path;
vector<string> ans;
int s;
void dfs(int root, int weight) {
	int i, size = forest[root].child.size(), nn, nw;
	if(size == 0) {
		if(weight == s) {
			string tmp, num;
			for(i = 0; i < path.size(); ++i) {
				num = to_string(path[i]);
				num.insert(num.begin(), 3 - num.size(), '0');
				tmp += (num + '-');
			}
			ans.emplace_back(tmp);
		}
		return;
	}
	for(i = 0; i < size; ++i) {
		nn = forest[root].child[i];
		nw = forest[nn].w;
		path.emplace_back(nw);
		dfs(nn, weight + nw);
		path.pop_back();
	}
}
int main() {
	int n, m, k, i, j, tmp;
	scanf("%d %d %lld", &n, &m, &s);
	for(i = 0; i < n; ++i) scanf("%d", &forest[i].w);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &tmp, &k);
		forest[tmp].child.resize(k);
		for(j = 0; j < k; ++j) scanf("%d", &forest[tmp].child[j]);
	}
	path.push_back(forest[0].w);
	dfs(0, forest[0].w);
	sort(ans.begin(), ans.end(), greater<string>());
	if(!ans.empty()) {
		for(j = 0; j < ans.size(); ++j) {
			for(i = 0; i < ans[j].size(); ++i) {
				if(isdigit(ans[j][i])) {
					k = i + 1;
					while(k < ans[j].size() && isdigit(ans[j][k])) ++k;
					printf("%d", atoi(ans[j].substr(i, k - i).c_str()));
					i = k - 1;
				}
				else if(i == ans[j].size() - 1) printf("\n");
				else printf(" ");
			}
		}
	} else printf("\n");
	return 0;
}
