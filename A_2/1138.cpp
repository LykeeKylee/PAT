#include<bits/stdc++.h>
using namespace std;
int n, preorder[50005], inorder[50005], ans;
map<int, int> position;
bool flag = false;
void find_first(int pos, int low, int high) {
	if(flag || low > high) return;
	int v = preorder[pos], mid;
	mid = position[v];
	find_first(pos + 1, low, mid - 1);
	find_first(pos + 1 + mid - low, mid + 1, high);
	if(!flag) {
		ans = v;
		flag = true;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", preorder + i);
	for(i = 0; i < n; ++i) {
		scanf("%d", inorder + i);
		position[inorder[i]] = i;
	}
	find_first(0, 0, n - 1);
	printf("%d", ans);
	return 0;
}
