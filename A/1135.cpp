#include<bits/stdc++.h>
using namespace std;
struct node {
	int num;
	int left;
	int right;
};
vector<node> rb;
int a[35];
int create(int low, int high) {
	if(low > high) return -1;
	int root = a[low], pos = high + 1;
	for(int i = low + 1; i <= high; ++i) {
		if(abs(root) < abs(a[i])) {
			pos = i;
			break;
		}
	}
	node t{root, create(low + 1, pos - 1), create(pos, high)};
	rb.emplace_back(t);
	return rb.size() - 1;
}
bool color(int root, int precolor) {
	bool cleft = true, cright = true, croot = !(precolor < 0 && rb[root].num < 0); 
	int curcolor = rb[root].num > 0 ? 1 : -1;
	if(rb[root].left != -1) cleft = color(rb[root].left, curcolor);
	if(rb[root].right != -1) cright = color(rb[root].right, curcolor);
	return cleft && cright && croot;
}
int black(int root, bool &check) {
	int bleft = 0, bright = 0, bcur = rb[root].num > 0 ? 1 : 0;
	if(rb[root].left != -1) bleft = black(rb[root].left, check);
	if(rb[root].right != -1) bright = black(rb[root].right, check);
	if(bleft != bright) check = false;
	return bcur + max(bleft, bright);
}
int main() {
	int k, n, i, j, root;
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		bool check = true;
		scanf("%d", &n);
		for(j = 0; j < n; ++j) scanf("%d", &a[j]);
		root = create(0, n - 1);
		if(rb[root].num < 0) check = false;
		else {
			check = color(root, 0);
			if(check) black(root, check);
		}
		if(check) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
