#include <bits/stdc++.h>
using namespace std;
string data[25];
int dleft[25], dright[25], exist[25];
void dfs(int cur, int root) {
	if(cur == -1) return;
	if(cur != root && (dleft[cur] != -1 || dright[cur] != -1)) printf("(");
	dfs(dleft[cur], root);
	printf("%s", data[cur].c_str());
	dfs(dright[cur], root);
	if(cur != root && (dleft[cur] != -1 || dright[cur] != -1)) printf(")");
} 
int main() {
	int n, root, i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		cin >> data[i] >> dleft[i] >> dright[i];
		if(dleft[i] != -1) exist[dleft[i]] = 1;
		if(dright[i] != -1) exist[dright[i]] = 1;
	}
	for(i = 1; i <= n; ++i) {
		if(exist[i] != 1) {
			root = i;
			break;
		}
	}
	dfs(root, root);
	return 0;
}
