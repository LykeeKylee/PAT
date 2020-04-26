#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i;
	scanf("%d", &n);
	long long a, b, c, d;
	for(i = 1; i <= n; ++i) {
		scanf("%lld %lld %lld", &a, &b, &c);
		d = a + b;
		if(a > 0 && b > 0 && d < 0) printf("Case #%d: true\n", i);
		else if(a < 0 && b < 0 && d >= 0) printf("Case #%d: false\n", i);
		else printf("Case #%d: %s\n", i, d > c ? "true" : "false"); 
	} 
	return 0;
}
