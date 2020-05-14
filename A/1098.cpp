#include<bits/stdc++.h>
using namespace std;
int seq[105];
int main() {
	int n, i, j, pos;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", &j);
	for(i = 1; i <= n; ++i) scanf("%d", seq + i);
	if(seq[1] < seq[2]) {
		for(i = 2; i <= n; ++i) {
			if(seq[i - 1] > seq[i]) {
				pos = i;
				break;
			}
		}
		int tg = seq[pos];
		j = pos - 1;
		while(seq[j] > tg) {
			seq[j + 1] = seq[j];
			--j;
		}
		seq[j + 1] = tg;
		printf("Insertion Sort\n");
		for(i = 1; i <= n; ++i) printf("%d%s", seq[i], (i == n ? "\n": " "));
	} else {
		int n_ = n;
		i = n;
		while(seq[i] > seq[i / 2]) --i, --n_;
		swap(seq[1], seq[i]);
		--n_;
		j = 1;
		while(j <= n_) {
			int leftc = j * 2, rightc = j * 2 + 1;
			if(leftc <= n_ && rightc <= n_) {
				int nextc = seq[leftc] > seq[rightc] ? leftc : rightc;
				if(seq[j] < seq[nextc]) swap(seq[j], seq[nextc]);
				j = nextc;
			} else if(leftc <= n_ && seq[j] < seq[leftc]) {
				swap(seq[j], seq[leftc]);
				j = leftc;
			} else if(rightc <= n_ && seq[j] < seq[rightc]) {
				swap(seq[j], seq[rightc]);
				j = rightc;
			}
			else break;
		}
		printf("Heap Sort\n");
		for(i = 1; i <= n; ++i) printf("%d%s", seq[i], (i == n ? "\n": " "));
	}
	return 0;
}
