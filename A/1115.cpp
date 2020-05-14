#include<bits/stdc++.h>
using namespace std;
struct node {
	int num;
	int level;
	int left;
	int right;
};
vector<node> v;
int maxlevel = 0;
int create(int root, int x, int level) {
	if(root == -1) {
		node t {x, level, -1, -1};
		v.emplace_back(t);
		maxlevel = level > maxlevel ? level : maxlevel;
		return v.size() - 1;
	}
	int ret;
	if(x <= v[root].num) {
		ret = create(v[root].left, x, level + 1);
		v[root].left = ret;
	} else {
		ret = create(v[root].right, x, level + 1);
		v[root].right = ret;
	}
	return root;
}
int main() {
	int n, i, j, head = -1;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		head = create(head, j, 1);
	}
	int n1 = maxlevel, n2 = max(maxlevel - 1, 0), cnt1 = 0, cnt2 = 0;
	queue<int> q;
	q.push(head);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		if(v[front].level == n1) ++cnt1;
		if(v[front].level == n2) ++cnt2;
		if(v[front].left != -1) q.push(v[front].left);
		if(v[front].right != -1) q.push(v[front].right);
	}
	printf("%d + %d = %d", cnt1, cnt2, cnt1 + cnt2);
	return 0;
}
