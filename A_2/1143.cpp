#include<bits/stdc++.h>
using namespace std;
int n, m, preorder[10005];
int x, y;
unordered_map<int, int> posMap;
unordered_map<int, bool> exist;
int lca(int pos, int low, int high) {
	int v = preorder[pos], mid, xpos = posMap[x], ypos = posMap[y];
	int i = low;
	while(i <= high) {
		if(v <= preorder[i]) break;
		++i;
	}
	mid = i;
	if(xpos == pos || ypos == pos || (xpos < mid && mid <= ypos) || (ypos < mid && mid <= xpos)) return pos;
	else if(xpos < mid && ypos < mid) return lca(low, low + 1, mid - 1);
	else if(xpos >= mid && ypos >= mid) return lca(mid, mid + 1, high);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j; 
	scanf("%d %d", &m, &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", preorder + i);
		posMap[preorder[i]] = i;
		exist[preorder[i]] = true;
	} 
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		auto e1 = exist[x],
			 e2 = exist[y];
			 
		if(!e1 && !e2) 
			printf("ERROR: %d and %d are not found.\n", x, y);
		else if(!e1 || !e2)
			printf("ERROR: %d is not found.\n", !e1 ? x : y);
		else {
//			int ans = preorder[lca(0, 1, n - 1)];
			int ans;
			for(j = 0; j < n; ++j) {
				ans = preorder[i];
				if(x <= ans && ans <= y || y <= ans && ans <= x) break;
			}
			if(ans == x || ans == y) 
				printf("%d is an ancestor of %d.\n", ans == x ? x : y, ans == x ? y : x);
			else
				printf("LCA of %d and %d is %d.\n", x, y, ans);
		}
	}
	return 0;
} 
