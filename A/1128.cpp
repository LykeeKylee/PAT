#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, n, i, j, k, chess[1005];
	scanf("%d", &m);
	for(i = 0; i < m; ++i) {
		bool check = true;
		scanf("%d", &n);
		for(j = 1; j <= n; ++j) scanf("%d", &chess[j]);
		for(j = 1; j <= n; ++j) {
			int x = j, y = chess[j];
			for(k = 1; k <= n; ++k) {
				if(k == x) continue;
				if(chess[k] == y) {
					check = false;
					break;
				}
				int yy = k + y - x;
				if(yy <= n && yy >= 1) {
					if(chess[k] == yy) {
						check = false;
						break;
					}
				}
				yy = -k + y + x;
				if(yy <= n && y >= 1) {
					if(chess[k] == yy) {
						check = false;
						break;
					}
				}
			}
		}
		if(check) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
