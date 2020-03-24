#include <bits/stdc++.h>
#define MAXHEAP 1
#define MINHEAP 2
#define NOTHEAP 0
#define NOTCHECK -1
using namespace std;

int a[1005], tmp[1005], type = NOTCHECK;

void check(int level) {
	for(int i = 1; i <= level; ++i) {
		if(level == 1) type = NOTCHECK;
		else {
			int st;
			if(i >= 2) {
				if(tmp[i-1] < tmp[i]) st = MINHEAP;
				else st = MAXHEAP;
				
				if(type == NOTCHECK) type = st;
				else if(type != st) type = NOTHEAP;
			}
		}
		printf("%d%s", tmp[i], (i==level ? "\n" : " "));
	}
}

void printHeap(int root, int level, int n) {
	int left = 2 * root, right = 2 * root + 1;
	tmp[level] = a[root];
	if(right <= n) printHeap(right, level + 1, n);
	if(left <= n) printHeap(left, level + 1, n);
	if(right > n && left > n)check(level);
}

int main() {
	int n, i;
	cin >> n;
	for(i = 1; i <= n; ++i) cin >> a[i];
	printHeap(1, 1, n);
	if(type == MAXHEAP) cout << "Max Heap";
	else if(type == MINHEAP) cout << "Min Heap";
	else cout << "Not Heap";
	return 0;
}
