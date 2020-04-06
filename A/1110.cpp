#include <bits/stdc++.h>
using namespace std;
int leftnode[21], rightnode[21], exist[21];
int main() {
	int n, i, j, head;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		string l, r;
		cin >> l >> r;
		if(l != "-") {
			leftnode[i] = atoi(l.c_str());
			exist[leftnode[i]] = true;
		}
		else leftnode[i] = -1;
		if(r != "-") {
			rightnode[i] = atoi(r.c_str()); 
			exist[rightnode[i]] = true;
		}
		else rightnode[i] = -1;
	}
	for(i = 0; i < n; ++i) {
		if(!exist[i]) {
			head = i;
			break;
		}
	}
	vector<int> ct(1);
	queue<int> q;
	q.push(head);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		ct.emplace_back(front);
		if(leftnode[front] != -1) q.push(leftnode[front]);
		if(rightnode[front] != -1) q.push(rightnode[front]);
	}
	bool legal = true;
	for(i = 1; i < ct.size() && legal; ++i) {
		if((i * 2 <= n && ct[i * 2] != leftnode[ct[i]]) || (i * 2 + 1 <= n && ct[i * 2 + 1] != rightnode[ct[i]])) legal = false;
	}
	if(legal) printf("%s %d\n", "YES", ct.back());
	else printf("%s %d\n", "NO", ct[1]);
	return 0;
}
