#include<bits/stdc++.h>
using namespace std;
int n, head;
vector<int> chain[100005];
double p, r;
int cnt = 0;
double ansp = -1.0;
void dfs(int root, double price) {
	if(chain[root].size() == 0) {
		if(price > ansp) {
			ansp = price;
			cnt = 1;
		}
		else if(price == ansp) ++cnt;
		return;
	}
	for(int i = 0; i < chain[root].size(); ++i) {
		dfs(chain[root][i], price * (1 + r / 100.0));
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	cin >> n >> p >> r;
	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		if(j == -1) head = i;
		else {
			chain[j].push_back(i);
		}
	}
	dfs(head, p);
	printf("%0.2lf %d", ansp, cnt);
	return 0;
}
