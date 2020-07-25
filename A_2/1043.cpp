#include<bits/stdc++.h>
using namespace std;
int n, preorder[1005];
vector<int> inorder, postorder;
bool flag1 = true, flag2 = true;
void dfs(int low, int high) {
	if(low > high || (!flag1 && !flag2)) return;
	int v = preorder[low], pos = high;
	for(int i = low + 1; i <= high; ++i) {
		if(i + 1 <= high && ((preorder[i] < v && v <= preorder[i + 1]) || (preorder[i] >= v && v > preorder[i + 1]))) {
			pos = i;
			break;
		}
	}
	for(int i = pos + 1; i <= high && flag1; ++i) {
		if(preorder[i] >= v) flag1 = false; 
	}
	for(int i = pos + 1; i <= high && flag2; ++i) {
		if(preorder[i] < v) flag2 = false;
	}
	dfs(low + 1, pos);
	inorder.push_back(v);
	dfs(pos + 1, high);
	postorder.push_back(v);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", preorder + i);
	dfs(0, n - 1);
	printf("%s", (flag1 || flag2) ? "YES\n" : "NO");
	for(i = 0; i < postorder.size() && (flag1 || flag2); ++i)
		printf("%d%s", postorder[i], i == postorder.size() - 1 ? "":" ");
	return 0;
}
