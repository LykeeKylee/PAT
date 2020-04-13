#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j, square, maxlen = 0, minstart;
	scanf("%d", &n);
	square = int(sqrt(n));
	for(i = 2; i <= square; ++i) {
		int tmp = n, len = 0;
		j = i;
		while(tmp >= j) {
			if(tmp % j == 0) {
				++len;
				tmp /= j;
			} else break;
			++j;
		}
		if(len > maxlen) {
			maxlen = len;
			minstart = i;
		}
	}
	if(maxlen == 0) {
		maxlen = 1;
		minstart = n;
	}
	printf("%d\n", maxlen);
	for(i = 0; i < maxlen; ++i) printf("%d%s", minstart + i, i == maxlen - 1 ? "\n" : "*");
	return 0;
}
