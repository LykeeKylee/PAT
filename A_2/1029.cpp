#include<bits/stdc++.h>
using namespace std;
int n1, n2, a[200005], b[200005];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d", &n1);
	for(i = 0; i < n1; ++i) scanf("%d", a + i);
	scanf("%d", &n2);
	for(i = 0; i < n2; ++i) scanf("%d", b + i);
	int cnt = 0, mid = (n1 + n2) % 2 == 0 ? (n1 + n2) / 2 : (n1 + n2 + 1) / 2, ans;
	i = j = 0;
	while(cnt < mid && i < n1 && j < n2) {
		++cnt;
		if(a[i] <= b[j]) ans = a[i++];
		else ans = b[j++];
	}
	if(cnt != mid) {
		if(i < n1) ans = a[i + mid - cnt - 1];
		else ans = b[j + mid - cnt - 1];
	}
	cout << ans << endl;
	return 0;
}
