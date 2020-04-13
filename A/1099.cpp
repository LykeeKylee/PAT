#include<bits/stdc++.h>
using namespace std;
int num[105], leftchild[105], rightchild[105], bst[105];
int get_node(int root) {
	if(root == -1) return 0;
	int leftnum = get_node(leftchild[root]), rightnum = get_node(rightchild[root]);
	return leftnum + rightnum + 1;
}
void fill_tree(int root, int low, int high) {
	if(root == -1 || low > high) return;
	int leftnum = get_node(leftchild[root]), rightnum = get_node(rightchild[root]);
	bst[root] = num[low + leftnum];
	fill_tree(leftchild[root], low, low + leftnum - 1);
	fill_tree(rightchild[root], low + leftnum + 1, high);
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d %d", leftchild + i, rightchild + i);
	for(i = 0; i < n; ++i) scanf("%d", num + i);
	sort(num, num + n);
	fill_tree(0, 0, n - 1);
	queue<int> q;
	q.push(0);
	bool flag = true;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%s%d", !flag ? " " : "", bst[front]);
		flag = false;
		if(leftchild[front] != -1) q.push(leftchild[front]);
		if(rightchild[front] != -1) q.push(rightchild[front]);
	}
	return 0;
} 
