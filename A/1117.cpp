#include <bits/stdc++.h>
using namespace std;
int num[100001];
int main() {
	int n, i, j, cur = -1, e = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", num + i);
	sort(num, num + n, greater<int>());
	for(i = 0; i < n; ++i) {
		if(num[i] - 1 < i + 1) break;
		++e;
	}
	cout << e;
	return 0;
} 
