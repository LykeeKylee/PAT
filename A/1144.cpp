#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, x, max_ = 1;
	map<int, int> num;
	cin >> n;
	for(i = 0; i < n; ++i) {
		scanf("%d", &x);
		num[x] = 1;
		max_ = max_ < x ? x : max_;
	}
	for(i = 1; i <= max_ + 1; ++i) {
		if(num[i] == 0) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}
