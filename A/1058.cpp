#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[2], b[2], c[2], i, x, y, z;
	for(i = 0; i < 2; ++i) scanf("%d.%d.%d", a + i, b + i, c + i);
	z = (c[0] + c[1]) % 29;
	i = (c[0] + c[1]) / 29;
	y = (b[0] + b[1] + i) % 17;
	i = (b[0] + b[1] + i) / 17;
	x = a[0] + a[1] + i;
	printf("%d.%d.%d\n", x, y, z);
	return 0;
}
