#include<bits/stdc++.h>
using namespace std;
int bst[1005], mirror = -1;
bool flag = true;
vector<int> ans;
void judge(int low, int high) {
	if(!flag) return;
	if(low == high) {
		ans.emplace_back(bst[low]);
		return;
	}
	int root = low, i, j, pos = low + 1, cnt = 0;
	for(i = low + 1; i < high; ++i) {
		if((bst[i] < bst[root] && bst[root] <= bst[i + 1]) || (bst[i] >= bst[root] && bst[root] > bst[i + 1])) {
			if(mirror == -1) {
				if(bst[i] < bst[root] && bst[root] <= bst[i + 1]) mirror = 0;
				else mirror = 1;
			}
			else {
				if((mirror == 1 && (bst[i] < bst[root] && bst[root] <= bst[i + 1])) || (mirror == 0 && (bst[i] >= bst[root] && bst[root] > bst[i + 1]))) flag = false;
			}
			pos = i;
			++cnt;
		}
	}
	if(cnt > 1) flag = false;
	else if(cnt == 0) judge(root + 1, high);
	else {
		judge(root + 1, pos);
		judge(pos + 1, high);
	}
	ans.emplace_back(bst[low]);
}
int main() {
	int n, i, j, pos1 = -1, pos2 = -1; 
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", bst + i);
	judge(0, n - 1);
	if(flag) {
		printf("YES\n");
		for(i = 0; i < ans.size(); ++i) printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
	}
	else printf("NO\n");
	return 0;
}
