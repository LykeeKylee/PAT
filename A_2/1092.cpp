#include<bits/stdc++.h>
using namespace std;
string bead1, bead2;
int cnt1[256], cnt2[256];
void count(string &bead, int cnt[]) {
	for(int i = 0; i < bead.length(); ++i) 
		cnt[int(bead[i])]++;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	getline(cin, bead1);
	getline(cin, bead2);
	count(bead1, cnt1);
	count(bead2, cnt2);
	int miss = 0;
	bool flag = true;
	for(i = 0; i < 256; ++i) {
		if(cnt1[i] < cnt2[i]) {
			flag = false;
			miss += cnt2[i] - cnt1[i];
		}
	}
	if(flag) printf("Yes %d\n", bead1.length() - bead2.length());
	else printf("No %d\n", miss);
	return 0;
}
