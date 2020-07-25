#include<bits/stdc++.h>
using namespace std;
int n, left_node[25], right_node[25];
bool visit[25];
vector<int> tree;
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
			left_node[i] = atoi(l.c_str());
			visit[left_node[i]] = true;
		}
		else left_node[i] = -1;
		if(r != "-") {
			right_node[i] = atoi(r.c_str());
			visit[right_node[i]] = true;
		}
		else right_node[i] = -1;
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
	bool flag = true;
	for(i = 0; i < n / 2; ++i) {
		int r = tree[i];
		if((i * 2 + 1 < n && left_node[r] != tree[i * 2 + 1]) || (i * 2 + 2 < n && right_node[r] != tree[i * 2 + 2])) {
			flag = false;
			break;
		}
	}
	if(flag) printf("YES %d", tree.back());
	else printf("NO %d", tree.front());
	return 0;
}
