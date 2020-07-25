#include<bits/stdc++.h>
using namespace std;
int n, num[1005], ans[1005];
vector<int> tree;
void dfs(int root) {
	if(root >= n) return;
	dfs(2 * root + 1);
	tree.push_back(root);
	dfs(2 * root + 2);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", num + i);
	sort(num, num + n);
	dfs(0);
	for(i = 0; i < tree.size(); ++i) ans[tree[i]] = num[i];
	for(i = 0; i < n; ++i)
		printf("%d%s", ans[i], i == n-1 ? "\n":" ");
	return 0;
} 
