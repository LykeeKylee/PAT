#include<bits/stdc++.h>
using namespace std;
vector<int> a, b, c(1);
int main() {
	int n, m, i, j, amid, bmid;
	scanf("%d", &n);
	a.resize(n + 1);
	for(i = 1; i <= n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m);
	b.resize(m + 1);
	for(i = 1; i <= m; ++i) scanf("%d", &b[i]);
	i = j = 1;
	while(i <= n && j <= m) {
		if(a[i] <= b[j]) c.emplace_back(a[i++]);
		else c.emplace_back(b[j++]);
	}
	while(i <= n) c.emplace_back(a[i++]);
	while(j <= m) c.emplace_back(b[j++]);
	printf("%d", c[(m + n) % 2 == 0 ? (m + n) / 2 : (m + n) / 2 + 1]);
	return 0;
}
