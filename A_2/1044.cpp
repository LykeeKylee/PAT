#include<bits/stdc++.h>
using namespace std;
const int msize = 100005, inf = 999999999;
struct strip {
	int l, r;
};
int sums[msize], best = inf;
vector<strip> choice;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, m, i, j, sum = 0;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &j);
		sum += j;
		sums[i] = sum;
	}
	for(i = 0; i <= n; ++i) {
		int l = i, r = n, mid, j = -1;
		while(l <= r) {
			mid = l + (r - l) / 2;
			if(sums[mid] - sums[i] == m) {
				j = mid;
				break;
			}
			else if(sums[mid] - sums[i] < m) l = mid + 1;
			else r = mid - 1; 
		}
		if(j == -1) j = l;
		strip t{i + 1, j};
		if(sums[j] - sums[i] < m) continue;
		if(sums[j] - sums[i] - m < best) {
			best = sums[j] - sums[i] - m;
			choice.clear();
			choice.push_back(t);
		}
		else if(sums[j] - sums[i] - m == best) 
			choice.push_back(t);
	}
	for(i = 0; i < choice.size(); ++i) 
		printf("%d-%d\n", choice[i].l, choice[i].r);
	return 0;
}
