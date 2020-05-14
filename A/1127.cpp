#include <bits/stdc++.h>
using namespace std;
struct node {
	int num;
	int left;
	int right;
	int level;
};
int inorder[31], postorder[31];
map<int, int> Hash;
vector<node> trees, levelorder;
int create(int low, int high, int post, int level) {
	if(low > high) return -1;
	int root = postorder[post], pos = Hash[postorder[post]], left, right;
	left = create(low, pos - 1, post - (high - pos) - 1, level + 1);
	right = create(pos + 1, high, post - 1, level + 1);
	node t {root, left, right, level};
	trees.emplace_back(t);
	return trees.size() - 1;
}
int main() {
	int n, i, j, root, flag = 1, cur;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", inorder + i);
		Hash[inorder[i]] = i;
	}
	for(i = 0; i < n; ++i) scanf("%d", postorder + i);
	root = create(0, n - 1, n - 1, 1);
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		node t = trees[q.front()];
		q.pop();
		levelorder.emplace_back(t);
		if(t.left != -1) q.push(t.left);
		if(t.right != -1) q.push(t.right);
	}
	cur = levelorder.begin()->level;
	vector<int> tmp;
	for(auto l = levelorder.begin(); l != levelorder.end(); ++l) {
		if(l->level != cur) {
			if(cur % 2 == 1) {
				for(auto t = tmp.rbegin(); t != tmp.rend(); ++t) printf("%s%d", (flag == 0 ? " " : ""), *t);
			} else {
				for(auto t = tmp.begin(); t != tmp.end(); ++t) printf("%s%d", (flag == 0 ? " " : ""), *t);
			}
			flag = 0;
			tmp.clear();
		}
		tmp.emplace_back(l->num);
		cur = l->level;
	}
	if(cur % 2 == 1) {
		for(auto t = tmp.rbegin(); t != tmp.rend(); ++t) printf("%s%d", (flag == 0 ? " " : ""), *t);
	} else {
		for(auto t = tmp.begin(); t != tmp.end(); ++t) printf("%s%d", (flag == 0 ? " " : ""), *t);
	}
	return 0;
}
