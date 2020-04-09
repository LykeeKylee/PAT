#include<bits/stdc++.h>
using namespace std;
bool flag = true;
void inorder(int root, int ln[], int rn[]) {
	if(root == -1) return;
	inorder(ln[root], ln, rn);
	printf("%s%d", !flag ? " " : "", root);
	flag = false;
	inorder(rn[root], ln, rn);
}
int main() {
	int n, i, j, ln[11], rn[11], root;
	char l, r;
	bool visit[11];
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		cin >> r >> l;
		if(isdigit(r)) {
			rn[i] = r - '0';
			visit[r - '0'] = true;
		}
		else rn[i] = -1;
		if(isdigit(l)) {
			ln[i] = l - '0';
			visit[l - '0'] = true;
		}
		else ln[i] = -1;
	}
	for(i = 0; i < n; ++i) {
		if(!visit[i]) {
			root = i;
			break;
		}
	}
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int j = q.front();
		q.pop();
		printf("%s%d", !flag ? " " : "", j);
		flag = false;
		if(ln[j] != -1) q.push(ln[j]);
		if(rn[j] != -1) q.push(rn[j]);
	}
	cout << endl;
	flag = true;
	inorder(root, ln, rn);
	cout << endl;
	return 0;
}
