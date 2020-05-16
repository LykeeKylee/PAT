#include<bits/stdc++.h>
using namespace std;
int v[100005], exist[100005];
int main() {
//#ifndef ONLINE_JUDEGE
//	freopen("data.txt", "r", stdin);
//#endif
	int n, m, i, j, half, flag = 0;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; ++i) {
		scanf("%d", v + i);
		++exist[v[i]];
	}
	sort(v, v + n);
	i = 0;
	half = m / 2;
	while(v[i] <= half) {
		if((v[i] == m - v[i] && exist[v[i]] > 1) || (v[i] != m - v[i] && exist[m - v[i]] > 0)) {
			printf("%d %d\n", v[i], m - v[i]);
			flag = 1;
			break;
		}
		++i;
	}
	if(flag == 0) printf("No Solution\n");
	return 0;
}
