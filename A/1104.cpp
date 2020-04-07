#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j;
	scanf("%d", &n);
	double sum = 0.0, t;
	for(i = 0; i < n; ++i) {
		scanf("%lf", &t);
		sum += (t * (i + 1) * (n - i));
	}
	printf("%.20lf\n", sum);
	return 0;
}


