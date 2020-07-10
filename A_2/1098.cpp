#include<bits/stdc++.h>
using namespace std;
int n, a[105], b[105];
bool judge() {
	int i, j;
	for(i = 0; i < n - 1; ++i) {
		if(b[i] > b[i + 1])
			break;
	}
	return i > 0;
//	for(j = i + 1; j < n; ++j) {
//		if(a[j] != b[j])
//			return false;
//	}
//	return true;
}
void heapfy(int root, int high) {
	int i = root, j = 2 * root + 1;
	while(j < high) {
		if(j + 1 < high && b[j] < b[j + 1])
			j = j + 1;
		if(b[i] < b[j]) {
			swap(b[i], b[j]);
			i = j;
			j = 2 * i + 1;
		} 
		else 
			break;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", a + i);
	for(i = 0; i < n; ++i) scanf("%d", b + i);
	if(judge()) {
		for(i = 0; i < n - 1; ++i) {
			if(b[i] > b[i + 1])
				break;
		}
		int tmp = b[i + 1];
		while(i >= 0) {
			if(b[i] > tmp) 
				b[i + 1] = b[i];
			else 
				break;
			--i;
		}
		b[i + 1] = tmp;
		printf("Insertion Sort\n");
	}
	else {
		for(i = n - 1; i >= 0; --i) {
			if(b[0] > b[i])
				break;
		}
		int high = i;
		swap(b[0], b[i]);
		heapfy(0, high);
		printf("Heap Sort\n");
	}
	for(i = 0; i < n; ++i) 
		printf("%d%s", b[i], i == n - 1 ? "\n" : " ");
	return 0;
}
