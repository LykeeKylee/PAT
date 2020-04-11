#include<bits/stdc++.h>
using namespace std;
map<int, int> num, next_;
map<int, bool> visit;
vector<int> ans, repeat;
int main() {
	int n, head, i, j;
	scanf("%d %d", &head, &n);
	for(i = 0; i < n; ++i) {
		int x_addr, x, x_next_;
		scanf("%d %d %d", &x_addr, &x, &x_next_);
		num[x_addr] = x;
		next_[x_addr] = x_next_;
	}
	i = head;
	while(i != -1) {
		if(!visit[abs(num[i])]) {
			visit[abs(num[i])] = true;
			ans.emplace_back(i);
		}
		else repeat.emplace_back(i);
		i = next_[i];
	}
	for(i = 0; i < ans.size(); ++i) {
		if(i == ans.size() - 1) printf("%05d %d %d\n", ans[i], num[ans[i]], -1);
		else printf("%05d %d %05d\n", ans[i], num[ans[i]], ans[i + 1]);
	}
	for(i = 0; i < repeat.size(); ++i) {
		if(i == repeat.size() - 1) printf("%05d %d %d\n", repeat[i], num[repeat[i]], -1);
		else printf("%05d %d %05d\n", repeat[i], num[repeat[i]], repeat[i + 1]);
	}
	return 0;
} 
