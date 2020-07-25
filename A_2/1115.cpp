#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	int left_node;
	int right_node;
	int level;
};
int n, max_level = 0, level_cnt[1005];
vector<node> bst;
int build(int root, int data, int level) {
	if(root == -1) {
		max_level = max_level < level ? level : max_level;
		level_cnt[level]++;
		node tmp{data, -1, -1, level};
		bst.push_back(tmp);
		return bst.size() - 1;
	}
	int root_data = bst[root].data, left_node = -1, right_node = -1;
	if(data <= root_data) {
        left_node = build(bst[root].left_node, data, level + 1);
		bst[root].left_node = left_node;
	}	
	else{
		right_node = build(bst[root].right_node, data, level + 1);
		bst[root].right_node = right_node;
	}
	return root;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j, root = -1;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		root = build(root, j, 1);
	}
	printf("%d + %d = %d\n", level_cnt[max_level], level_cnt[max_level - 1], level_cnt[max_level] + level_cnt[max_level - 1]);
	return 0;
} 
