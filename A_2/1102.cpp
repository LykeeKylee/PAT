#include<bits/stdc++.h>
using namespace std;
int n, left_node[25], right_node[25];
bool visit[25], blank = false;
vector<int> tree;
void dfs(int root) {
	if(root != -1) {
		dfs(left_node[root]);
		if(blank) printf(" ");
		blank = true;
		printf("%d", root);
		dfs(right_node[root]);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		string l, r;
		cin >> l >> r;
		if(l != "-") {
			right_node[i] = atoi(l.c_str());
			visit[right_node[i]] = true;
		}
		else right_node[i] = -1;
		if(r != "-") {
			left_node[i] = atoi(r.c_str());
			visit[left_node[i]] = true;
		}
		else left_node[i] = -1;
	}
	int root;
	for(i = 0; i < n; ++i) {
		if(!visit[i]) {
			root = i;
			break;
		}
	}
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int top = q.front();
		tree.push_back(top);
		q.pop();
		if(left_node[top] != -1) q.push(left_node[top]);
		if(right_node[top] != -1) q.push(right_node[top]);
	}
	for(i = 0; i < tree.size(); ++i) {
		printf("%d", tree[i]);
		if(i == tree.size() - 1) printf("\n");
		else printf(" ");
	}
	dfs(root);
	return 0;
}
