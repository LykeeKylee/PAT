#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, l, r;
};
vector<node> trees;
bool flag = true;
void postorder(int root) {
	if(root == -1) return;
	postorder(trees[root].l);
	postorder(trees[root].r);
	printf("%s%d", flag ? "" : " ", trees[root].x);
	flag = false;
}
int main() {
	int n, i, x, cur = -1;
	string op, preop;
	stack<int> inorder;
	scanf("%d", &n);
	for(i = 0; i < 2 * n; ++i) {
		cin >> op;
		if(op == "Push") {
			cin >> x;
			node tmp {x, -1, -1};
			trees.emplace_back(tmp);
			int pos = trees.size() - 1;
			inorder.push(pos);
			if(cur != -1) {
				if(preop == "Push") trees[cur].l = pos;
				else trees[cur].r = pos;
			}
			cur = pos;
			preop = op;
		} else {
			cur = inorder.top();
			inorder.pop();
			preop = op;
		}
	}
	postorder(0);
	return 0;
}
