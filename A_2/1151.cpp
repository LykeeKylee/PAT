#include<bits/stdc++.h>
using namespace std;
struct node {
	int value;
	int leftNode;
	int rightNode;
};
int n, m, preorder[10005], inorder[10005];
int x, y;
unordered_map<int, int> posMap;
unordered_map<int, bool> exist;
vector<node> btree;
int build(int pos, int low, int high) {
	if(low > high) return -1;
	int x = preorder[pos], mid, leftNode, rightNode;
	mid = find(inorder, inorder + n, x) - inorder;
	leftNode = build(pos + 1, low, mid - 1);
	rightNode = build(pos + mid - low + 1, mid + 1, high);
	node tmp{x, leftNode, rightNode};
	btree.push_back(tmp);
	return btree.size() - 1;
}
int lca(int pos, int low, int high) {
	if(low > high) return -1;
	int v = preorder[pos], mid, xpos = posMap[x], ypos = posMap[y];
	mid = posMap[v];
	if((xpos < mid && mid < ypos) || (ypos < mid && mid < xpos) || xpos == mid || ypos == mid) return mid;
	else if(xpos < mid && ypos < mid) return lca(pos + 1, low, mid - 1);
	else if(xpos >mid && ypos > mid) return lca(pos + mid - low + 1, mid + 1, high);
}
void show(int root) {
	if(root != -1) {
		show(btree[root].leftNode);
		cout << btree[root].value << ' ';
		show(btree[root].rightNode); 
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j; 
	scanf("%d %d", &m, &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", inorder + i);
		posMap[inorder[i]] = i;
		exist[inorder[i]] = true;
	} 
	for(i = 0; i < n; ++i) scanf("%d", preorder + i);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		auto e1 = exist[x],
			 e2 = exist[y];
		if(!e1 && !e2) 
			printf("ERROR: %d and %d are not found.\n", x, y);
		else if(!e1 || !e2)
			printf("ERROR: %d is not found.\n", !e1 ? x : y);
		else {
			int ans = inorder[lca(0, 0, n - 1)];
			if(ans == x || ans == y) 
				printf("%d is an ancestor of %d.\n", ans == x ? x : y, ans == x ? y : x);
			else
				printf("LCA of %d and %d is %d.\n", x, y, ans);
		}
	}
	return 0;
} 
