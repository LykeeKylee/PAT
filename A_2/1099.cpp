#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	int left_node;
	int right_node;
};
int n, nums[105];
vector<node> tree;
vector<int> inorder;
bool visit[105];
void dfs(int root) {
	if(root != -1) {
		dfs(tree[root].left_node);
		inorder.push_back(root);
		dfs(tree[root].right_node);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		node tmp;
		scanf("%d %d", &tmp.left_node, &tmp.right_node);
		if(tmp.left_node != -1) visit[tmp.left_node] = true;
		if(tmp.right_node != -1) visit[tmp.right_node] = true;
		tree.push_back(tmp);
	}
	for(i = 0; i < n; ++i) scanf("%d", nums + i);
	int root;
	for(i = 0; i < n; ++i) {
		if(!visit[i]) {
			root = i;
			break;
		}
	}
	sort(nums, nums + n);
	dfs(root);
	for(i = 0; i < n; ++i)
		tree[inorder[i]].data = nums[i];
	queue<int> q;
	q.push(root);
	bool flag = false;
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		printf("%s%d", flag ? " ":"", tree[front].data);
		flag = true;
		if(tree[front].left_node != -1) q.push(tree[front].left_node);
		if(tree[front].right_node != -1) q.push(tree[front].right_node); 
	}
	return 0;
}
