#include <bits/stdc++.h>
using namespace std;
int heaps[1005];
void post(int root, int n) {
	if(root > n) return;
	post(root * 2, n);
	post(root * 2 + 1, n);
	printf("%d%s", heaps[root], (root == 1 ? "\n": " "));
}
int main() {
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	for(j = 0; j < m; ++j) {
		for(i = 1; i <= n; ++i) scanf("%d", &heaps[i]);
		int maxt = 1, mint = 1;
		for(i = 2; i <= n; ++i) {
			if(heaps[i / 2] < heaps[i]) maxt = 0;
			if(heaps[i / 2] > heaps[i]) mint = 0;
		}
		if(maxt == 1) printf("Max Heap\n");
		else if(mint == 1) printf("Min Heap\n");
		else printf("Not Heap\n");
		post(1, n);
	}
	return 0;
}
