#include<bits/stdc++.h>
using namespace std;
int n, preorder[35], postorder[35];
map<int, int> position1, position2;
bool flag = true;
vector<int> ans;
void dfs(int low1, int high1, int low2, int high2) {
	if(low1 > high1) return;
	else if(low1 == high1) {
		ans.push_back(preorder[low1]);
		return;
	} 
	if(high1 == low1 + 1) flag = false;
	int v1 = preorder[low1 + 1], v2 = postorder[high2 - 1];
	int pos1 = position1[v2], pos2 = position2[v1];
	dfs(low1 + 1, pos1 - 1, low2, pos2);
	ans.push_back(preorder[low1]);
	dfs(pos1, high1, pos2 + 1, high2 - 1);                                                                                                                                                                                                                                                                                                                                                                     
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", preorder + i);
		position1[preorder[i]] = i;
	}
	for(i = 0; i < n; ++i) {
		scanf("%d", postorder + i);
		position2[postorder[i]] = i;
	}
	dfs(0, n - 1, 0, n - 1);
	printf("%s\n", flag ? "Yes" : "No");
	for(i = 0; i < ans.size(); ++i) {
		if(i != 0) printf(" ");
		printf("%d", ans[i]);
	}
	cout << endl;
	return 0;
} 
