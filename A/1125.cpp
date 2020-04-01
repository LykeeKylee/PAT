#include <bits/stdc++.h>
using namespace std;
double rope[10001];
int main() {
	int n, i, j;
	double prelen = 0.0, maxlen = 0.0, len;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%lf", rope + i);
	sort(rope, rope + n);
	for(i = 0; i < n; ++i) {
		if(i == 0) prelen = rope[i];
		else {
			prelen = prelen / 2 + rope[i] / 2;
		}
		maxlen = maxlen < prelen ? prelen : maxlen;
	}
	cout << int(floor(maxlen));
	return 0;
}
