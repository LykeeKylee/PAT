#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	int left_node;
	int right_node;
	int level;
};
int n, inorder[35], postorder[35];
map<int, int> position;
vector<node> tree;
int build(int pos, int low, int high, int level) {
	if(low > high) return -1;
	int value = postorder[pos], mid;
	mid = position[value];
	node tmp;
	tmp.data = value;
	tmp.level = level;
	tmp.left_node = build(pos - high + mid - 1, low, mid - 1, level + 1);
	tmp.right_node = build(pos - 1, mid + 1, high, level + 1);
	tree.push_back(tmp);
	return tree.size() - 1;
}
void show(int root) {
	queue<int> node_queue;
	vector<node> showlist;
	vector<node> showlist_rev;
	node_queue.push(root);
	while(!node_queue.empty()) {
		auto top = node_queue.front();
		node_queue.pop();
		showlist.push_back(tree[top]);
		if(tree[top].left_node != -1) node_queue.push(tree[top].left_node);
		if(tree[top].right_node != -1) node_queue.push(tree[top].right_node);
	}
	node_queue.push(root);
	while(!node_queue.empty()) {
		auto top = node_queue.front();
		node_queue.pop();
		showlist_rev.push_back(tree[top]);
		if(tree[top].right_node != -1) node_queue.push(tree[top].right_node);
		if(tree[top].left_node != -1) node_queue.push(tree[top].left_node);
	}
	for(int i = 0; i < n; ++i) {
		if(showlist[i].level % 2 == 0) printf("%s%d", i == 0 ? "" : " ", showlist[i].data);
		else printf("%s%d", i == 0 ? "" : " ", showlist_rev[i].data);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", inorder + i);
		position[inorder[i]] = i;
	}
	for(i = 0; i < n; ++i) 
		scanf("%d", postorder + i);
	int root = build(n - 1, 0, n - 1, 1);
	show(root);
	return 0;
}
