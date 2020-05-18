#include<bits/stdc++.h>
using namespace std;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int m, n, k, i, j, l, a[1005];
	scanf("%d %d %d", &m, &n, &k);
	for(i = 0; i < k; ++i) {
		for(j = 0; j < n; ++j) scanf("%d", a + j);
		stack<int> s;
		l = 0;
		for(j = 1; j <= n; ++j) {
			s.push(j);
			if(s.size() > m) break;
			while(!s.empty() && s.top() == a[l]) {
				s.pop();
				++l;
			}
		}
		// Every element in the stack was popped normally.
		if(l >= n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
