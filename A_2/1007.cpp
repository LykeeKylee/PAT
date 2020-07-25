#include<bits/stdc++.h>
using namespace std;
int k, seq[10005], dp[10005];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j, neg = 0;
	scanf("%d", &k);
	for(i = 0; i < k; ++i) {
		scanf("%d", seq + i);
		if(seq[i] < 0) ++neg;
	}
	if(neg == k) printf("%d %d %d", 0, seq[0], seq[k - 1]);
	else {
		int pos, maxdp = -1;
		for(i = 0; i < k; ++i) {
			if(i == 0) {
				dp[i] = maxdp = seq[i];
				pos = 0; 
			} 
			else {
				dp[i] = max(dp[i - 1] + seq[i], seq[i]);
				if(dp[i] > maxdp) {
					maxdp = dp[i];
					pos =  i;
				}
			}
		}
		int remain = maxdp;
		i = pos;
		while(remain != 0) {
			remain -= seq[i--];
		}
		while(i >= 0 && seq[i] == 0) --i;
		printf("%d %d %d", maxdp, seq[i + 1], seq[pos]); 
	}
	return 0;
} 
