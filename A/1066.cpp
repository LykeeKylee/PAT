#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, left, right;
};
vector<node> avl;
int LL(int root) {
	int p = avl[root].left;
	avl[root].left = avl[p].right;
	avl[p].right = root;
	return p;
}
int RR(int root) {
	int p = avl[root].right;
	avl[root].right = avl[p].left;
	avl[p].left = root;
	return p;
}
int LR(int root) {
	int p = avl[root].left;
	avl[root].left = RR(p);
	return LL(root);
}
int RL(int root) {
	int p = avl[root].right;
	avl[root].right = LL(p);
	return RR(root);
}
int getDepth(int root) {
	if(root == -1) return 0;
	return max(getDepth(avl[root].left), getDepth(avl[root].right)) + 1;
}
int insert(int pos, int root) {
	if(root == -1) return pos;
	int p;
	if(avl[pos].x < avl[root].x) {
		p = insert(pos, avl[root].left);
		avl[root].left = p;
		if(getDepth(avl[root].left) - getDepth(avl[root].right) > 1) {
			p = avl[pos].x < avl[avl[root].left].x ? LL(root) : LR(root);
			root = p;
		}
	}
	else {
		p = insert(pos, avl[root].right);
		avl[root].right = p;
		if(getDepth(avl[root].right) - getDepth(avl[root].left) > 1) {
			p = avl[pos].x < avl[avl[root].right].x ? RL(root) : RR(root);
			root = p;
		}
	}
	return root;
}
int main() {
	int n, i, j, root = -1;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		node tmp = {j, -1, -1};
		avl.emplace_back(tmp);
		root = insert(avl.size() - 1, root);
	}
	cout << avl[root].x << endl;
	return 0;
}
