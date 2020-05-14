#include<bits/stdc++.h>
using namespace std;
int Next[100005];
bool visit[100005];
int main() {
	int w1, w2, n, i, j, p1, p2;
	scanf("%d %d %d", &w1, &w2, &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		getchar();
		getchar();
		scanf("%d", &Next[j]);
	}
	
	i = w1;
	while(i != -1) {
		visit[i] = true;
		i = Next[i];
	}
	j = w2;
	while(j != -1) {
		if(visit[j]) break;
		j = Next[j];
	}
	if(j == -1) printf("-1\n");
	else printf("%05d\n", j);
	return 0;
}
