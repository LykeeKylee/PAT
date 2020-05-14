#include <bits/stdc++.h>
using namespace std;
int pre[32], post[32];
map<int, int> ppre, ppost;
bool unique_ = true;
vector<int> inorder;
void search(int pre_low, int pre_high, int post_low, int post_high) {
//	cout << "*" << pre_low << ' ' << pre_high << ' ' << post_low << ' ' << post_high << endl;
	if(pre_low > pre_high) return;
	if(pre_low == pre_high) {
		inorder.emplace_back(pre[pre_low]);
		return;
	}
	int pre_next = pre_low + 1;
	int pos = ppost[pre[pre_next]];
	if(pos == post_high - 1) unique_ = false;
	int len = pos - post_low + 1;
	search(pre_next, pre_next + len - 1, post_low, pos);
	inorder.emplace_back(pre[pre_low]);
	search(pre_next + len, pre_high, pos + 1, post_high - 1);
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", pre + i);
		ppre[pre[i]] = i;
	}
	for(i = 0; i < n; ++i) {
		scanf("%d", post + i);
		ppost[post[i]] = i;
	}
	search(0, n-1, 0, n-1);
	printf("%s\n", unique_ ? "Yes" : "No");
	for(i = 0; i < inorder.size(); ++i) printf("%d%s", inorder[i], i == inorder.size() - 1 ? "\n" : " ");
	return 0;
}
