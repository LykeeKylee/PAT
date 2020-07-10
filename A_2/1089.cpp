#include<bits/stdc++.h>
using namespace std;
int n, a[105], b[105];
bool judge() {
	int i, j;
	for(i = 0; i < n - 1; ++i) {
		if(b[i] > b[i + 1])
			break;
	}
	for(j = i + 1; j < n; ++j) {
		if(a[j] != b[j])
			return false;
	}
	return true;
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
		for(i = 0; i < n; ++i) 
		printf("%d%s", b[i], i == n - 1 ? "\n" : " ");
	}
	else {
		int len = 2;
		bool flag = false;
		while(!flag) {
			for(i = 0; i < n; i += len) {
				if(i + len < n) sort(a + i, a + i + len);
				else sort(a + i, a + n);
			}
			flag = true;
			for(i = 0; i < n; ++i) {
				if(a[i] != b[i]) {
					flag = false;
					break;
				}
			}
			len *= 2;
		}
		for(i = 0; i < n; i += len) {
			if(i + len < n) sort(a + i, a + i + len);
			else sort(a + i, a + n);
		}
		printf("Merge Sort\n");
		for(i = 0; i < n; ++i) 
		printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
	}
	
	return 0;
}
