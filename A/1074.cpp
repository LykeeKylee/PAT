#include<bits/stdc++.h>
using namespace std;
int x[1000002], xnext[1000002];
int main() {
	int head, n, k, i, j, addr, naddr, cnt;
	scanf("%d %d %d", &head, &n, &k);
	for(i = 0; i < n; ++i) {
		scanf("%d %d %d", &addr, &j, &naddr);
		x[addr] = j;
		xnext[addr] = naddr;
	}
	i = head;
	vector<int> seq;
	while(i != -1) {
		seq.emplace_back(i);
		i = xnext[i];
	}
	for(i = 0; i < seq.size(); ++i) {
		if((i + 1) % k == 0) {
			for(j = 0; j < k / 2; ++j) swap(seq[i - j], seq[i - k + 1 + j]);
		}
	}
	for(i = 0; i < seq.size(); ++i) {
		if(i == seq.size() - 1) printf("%05d %d %d\n", seq[i], x[seq[i]], -1);
		else printf("%05d %d %05d\n", seq[i], x[seq[i]], seq[i + 1]);  
	}
	return 0;
}





