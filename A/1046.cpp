#include<bits/stdc++.h>
using namespace std;
int dcnt[100005];
int main() {
	int n, m, i, j, t, cnt = 0, x, y;
	scanf("%d", &n);
	dcnt[1] = 0;
	for(i = 2; i <= n + 1; ++i) {
		scanf("%d", &t);
		cnt += t;
		dcnt[i] = cnt;
	}
	scanf("%d", &m);
	for(i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		if(x > y) swap(x, y);
		t = dcnt[y] - dcnt[x];
		printf("%d\n", cnt - t > t ? t : cnt - t);
	}
	return 0;
}
