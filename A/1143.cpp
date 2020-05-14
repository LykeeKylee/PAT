#include <bits/stdc++.h>
using namespace std;
int bst[10005];
int lca(int low, int upper, int u, int v) {
	int root = bst[low], mid = low, i;
	for(i = low + 1; i <= upper; ++i) {
		if(bst[i] >= root) {
			mid = i;
			break;
		}
	}
	if(u <= root && v >= root) return root;
	else if(v < root) return lca(low + 1, mid - 1, u, v);
	else if(u > root) return lca(mid, upper, u, v);
}
int main() {
	int n, m, i, j, u, v;
	scanf("%d %d", &m, &n);
	for(i = 0; i < n; ++i) scanf("%d", &bst[i]);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &u, &v);
		int pu = find(bst, bst + n, u) - bst,
			pv = find(bst, bst + n, v) - bst;
		if(pu == n && pv == n) printf("ERROR: %d and %d are not found.\n", u, v);
		else if(pu == n) printf("ERROR: %d is not found.\n", u);
		else if(pv == n) printf("ERROR: %d is not found.\n", v);
		else {
			int tu = u, tv = v;
			if(u > v) swap(u, v);
			int anc = lca(0, n - 1, u, v);
			if(anc != tu && anc != tv) printf("LCA of %d and %d is %d.\n", tu, tv, anc);
			else if(anc == tu) printf("%d is an ancestor of %d.\n", tu, tv);
			else if(anc == tv) printf("%d is an ancestor of %d.\n", tv, tu);
		} 
	}
	return 0;
}


