#include<bits/stdc++.h>
using namespace std;
struct node {
	string data;
	int left_child;
	int right_child;
};
int n, broot;
bool exist[25];
vector<node> btree(1);
void inorder(int root) {
	if(root == -1) return;
	string data = btree[root].data;
	if(root != broot && data.size() == 1 && !isalnum(data[0]))
		printf("(");
	inorder(btree[root].left_child);
	printf("%s", data.c_str());
	inorder(btree[root].right_child);
	if(root != broot && data.size() == 1 && !isalnum(data[0]))
		printf(")");
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		node tmp;
		cin >> tmp.data;
		scanf("%d %d", &tmp.left_child, &tmp.right_child);
		if(tmp.left_child != -1)
			exist[tmp.left_child] = true;
		if(tmp.right_child != -1)
			exist[tmp.right_child] = true;
		btree.push_back(tmp);
	}
	for(i = 1; i <= n; ++i) {
		if(!exist[i]) {
			broot = i;
			break;
		}
	}
	inorder(broot);
	return 0;
}
