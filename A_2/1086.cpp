#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> inorder, preorder, ans;
map<int, int> nump;
void dfs(int pos, int low, int high) {
	if(low > high) return;
	int value = preorder[pos], mid;
	mid = nump[value];
	dfs(pos + 1, low, mid - 1);
	dfs(pos + 1 + mid - low, mid + 1, high);
	ans.push_back(value);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	char op[5];
	stack<int> s;
	while(~scanf("%s", op)) {
		if(strlen(op) == 4) {
			scanf("%d", &j);
			preorder.push_back(j);
			s.push(j);
		}
		else {
			inorder.push_back(s.top());
			nump[s.top()] = inorder.size() - 1;
			s.pop();
		}
	}
	dfs(0, 0, n - 1);
	for(i = 0; i < ans.size(); ++i) {
		printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
	}
	return 0;
}
