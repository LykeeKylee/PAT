#include<bits/stdc++.h>
using namespace std;
int n, m, levelorder[1005];
bool flag1 = true, flag2 = true;
vector<int> postorder;
void judge() {
	flag1 = flag2 = true;
	for(int i = 0; i < n / 2 && (flag1 || flag2); ++i) {
		if((i * 2 + 1 < n && levelorder[i] < levelorder[i * 2 + 1]) || (i * 2 + 2 < n && levelorder[i] < levelorder[i * 2 + 2])) flag1 = false;
		if((i * 2 + 1 < n && levelorder[i] > levelorder[i * 2 + 1]) || (i * 2 + 2 < n && levelorder[i] > levelorder[i * 2 + 2])) flag2 = false;
	}
}
void dfs(int root) {
	if(root < n) {
		dfs(2 * root + 1);
		dfs(2 * root + 2);
		postorder.push_back(root);
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &m, &n);
	dfs(0);
	for(j = 0; j < m; ++j) {
		for(i = 0; i < n; ++i) 
			scanf("%d", levelorder + i);
		judge();
	 	if(!flag1 && !flag2) printf("Not Heap\n");
	 	else if(flag1) printf("Max Heap\n");
	 	else if(flag2) printf("Min Heap\n");
	 	for(i = 0; i < n; ++i) {
	 		printf("%d%s", levelorder[postorder[i]], i == n - 1 ? "\n":" ");
		 }
	}
	return 0;
}
