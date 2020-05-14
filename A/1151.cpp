#include<bits/stdc++.h>
using namespace std;
int pre[10005], in[10005];
//void find_target(int target_pos, int prelow, int preupper, int inlow, int inupper, int n, vector<int> &trace, map<int, int> &hash) {
//	if(pre[prelow] == in[target_pos]) {
//		trace.push_back(pre[prelow]);
//		return;
//	}
//	int root = pre[prelow];
//	trace.push_back(root);
//	int pos = hash[root];
//	if(target_pos < pos) find_target(target_pos, prelow + 1, prelow + pos - inlow, inlow, pos - 1, n, trace, hash);
//	else find_target(target_pos, prelow + pos - inlow + 1, prelow + pos - inlow + inupper - pos, pos + 1, inupper, n, trace, hash);
//}
void lca(int pos_x, int pos_y, int prelow, int preupper, int inlow, int inupper, map<int, int> &hash) {
	if(inlow > inupper) return;
	int root = pre[prelow], x = in[pos_x], y = in[pos_y];
	int pos = hash[root];
	if(pos_x == pos_y) printf("%d is an ancestor of %d.\n", x, x);
	else if((pos_x < pos && pos < pos_y) || (pos_x > pos && pos > pos_y)) printf("LCA of %d and %d is %d.\n", x, y, root);
	else if(pos_x == pos) printf("%d is an ancestor of %d.\n", x, y);
	else if(pos_y == pos) printf("%d is an ancestor of %d.\n", y, x);
	else if(pos_x < pos && pos > pos_y) lca(pos_x, pos_y, prelow + 1, prelow + pos - inlow, inlow, pos - 1, hash);
	else if(pos_x > pos && pos < pos_y) lca(pos_x, pos_y, prelow + pos - inlow + 1, prelow + pos - inlow + inupper - pos, pos + 1, inupper, hash);
}
int main() {
	int m, n, i, j, x, y;
	map<int, int> hash;
	scanf("%d %d", &m, &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &in[i]);
		hash[in[i]] = i;
	}
	for(i = 1; i <= n; ++i) scanf("%d", &pre[i]);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		int posx = hash[x], posy = hash[y];
		if(posx == 0 && posy == 0) printf("ERROR: %d and %d are not found.\n", x, y);
		else if(posx == 0) printf("ERROR: %d is not found.\n", x);
		else if(posy == 0) printf("ERROR: %d is not found.\n", y);
		else {
//			vector<int> x_trace, y_trace;
//			find_target(posx, 1, n, 1, n, n, x_trace, hash);
//			find_target(posy, 1, n, 1, n, n, y_trace, hash);
//			int len = x_trace.size() < y_trace.size() ? x_trace.size() : y_trace.size();
//			for(j = -1; j < len - 1; ++j) {
//				if(x_trace[j + 1] != y_trace[j + 1]) break;
//			}
//			if(j == len - 1 && x_trace.size() < y_trace.size()) printf("%d is an ancestor of %d.\n", x, y);
//			else if(j == len - 1 && x_trace.size() > y_trace.size()) printf("%d is an ancestor of %d.\n", y, x);
//			else if(j == len - 1 && x_trace.size() == y_trace.size()) printf("%d is an ancestor of %d.\n", x, x);
//			else printf("LCA of %d and %d is %d.\n", x, y, x_trace[j]);
			lca(posx, posy, 1, n, 1, n, hash);
		}
	}
	return 0;
}
