#include<bits/stdc++.h>
using namespace std;
long long seq[100000];
int main() {
	int n, i, j, max_size = 1;
	long long p, max_;
	scanf("%d %lld", &n, &p);
	for(i = 0; i < n; ++i) scanf("%lld", seq + i);
	sort(seq, seq + n);
	for(i = 0; i < n; ++i) {
		for(j = i + max_size; j < n; ++j) {
			if(seq[i] * p >= seq[j]) ++max_size;
			else break;
		}
	}
	printf("%d\n", max_size);
	return 0; 
}
