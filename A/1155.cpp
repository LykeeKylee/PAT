#include <bits/stdc++.h>
using namespace std;
int a[1005], tmp[1005];
void printHeap(int root, int level, int n) {
	int left = 2 * root, right = 2 * root + 1;
	tmp[level] = a[root];
	if(right <= n) printHeap(right, level + 1, n);
	if(left <= n) printHeap(left, level + 1, n);
	if(right > n && left > n) {
	    for(int i = 1; i <= level; ++i)
	        printf("%d%s", tmp[i], (i == level ? "\n":" "));
	}
}
int main() {
	int n, i, maxt = 1, mint = 1;
	cin >> n;
	for(i = 1; i <= n; ++i) cin >> a[i];
	for(i = 2; i <= n; ++i) {
	    if(a[i / 2] < a[i]) maxt = 0;
	    if(a[i / 2] > a[i]) mint = 0;
	}
	printHeap(1, 1, n);
	if(maxt == 1) cout << "Max Heap";
	else if(mint == 1) cout << "Min Heap";
	else cout << "Not Heap";
	return 0;
}
