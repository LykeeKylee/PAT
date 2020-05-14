#include<bits/stdc++.h>
using namespace std;
int a1[105], a2[105];
int main() {
	int n, i, j, pre, pos = -1, type = 1;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", a1 + i);
	for(i = 0; i < n; ++i) {
		scanf("%d", a2 + i);
		if(i == 0) pre = a2[i];
		else if(a2[i] >= pre) pre = a2[i];
		else if(pos == -1) pos = i;
		if(pos != -1 && a1[i] != a2[i]) type = 2;
	}
	if(type == 1) {
		j = a2[pos];
		i = pos - 1;
		while(i >= 0 && a2[i] > j) {
			a2[i + 1] = a2[i];
			--i;
		}
		a2[i + 1] = j;
		printf("Insertion Sort\n");
		for(i = 0; i < n; ++i) printf("%d%s", a2[i], i == n - 1 ? "\n" : " ");
	} else {
		j = 2;
		bool match = false;
		while(!match) {
			for(i = 0; i < n; i += j) {
				if(i + j > n) sort(a1 + i, a1 + n);
				else sort(a1 + i, a1 + i + j);
			}
			bool flag = true;
			for(i = 0; i < n; ++i) {
				if(a1[i] != a2[i]) {
					flag = false;
					break;
				}
			}
			if(flag) match = true;
			else j *= 2;
		}
		j *= 2;
		for(i = 0; i < n; i += j) {
			if(i + j > n) sort(a1 + i, a1 + n);
			else sort(a1 + i, a1 + i + j);
		}
		printf("Merge Sort\n");
		for(i = 0; i < n; ++i) printf("%d%s", a1[i], i == n - 1 ? "\n" : " ");
	}
	return 0;
}
