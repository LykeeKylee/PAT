#include<bits/stdc++.h>
using namespace std;
int bet[100005], cnt[10005];
int main() {
	int n, i, j, unique = -1;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", bet + i);
		++cnt[bet[i]];
	}
	for(i = 0; i < n; ++i) {
		if(cnt[bet[i]] == 1) {
			unique = bet[i];
			break;
		}
	}
	if(unique == -1) printf("None\n");
	else printf("%d\n", unique);
	return 0;
}
