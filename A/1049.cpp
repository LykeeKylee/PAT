#include<bits/stdc++.h>
using namespace std;
int number_cnt[101], one_cnt[101];
int main() {
	int n, m, right, left, mid, cnt = 0, k = 1;
	scanf("%d", &n);
	while(n / k) {
		left = n / k / 10;
		right = n % k;
		mid = n / k % 10;
		// 当每一位等于1时的各种情况
		// size(0, left - 1) * size(0, k - 1), k = 1, 10, 100, ... 
		if(mid == 0) cnt += (left * k);
		// size(0, left - 1) * size(0, k - 1) + size(0, right) when left
		else if(mid == 1) cnt += (left * k + right + 1);
		// size(0, left) * size(0, k - 1)
		else cnt += ((left + 1) * k);
		k *= 10;
	}
	printf("%d\n", cnt);
	return 0;
}
