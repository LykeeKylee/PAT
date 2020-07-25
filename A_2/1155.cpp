#include<bits/stdc++.h>
using namespace std;
int n, levelorder[1005];
bool flag1, flag2, printflag = true;
vector<int> tmp;
void dfs(int root) {
	if(root < n) {
		tmp.push_back(levelorder[root]);
		dfs(2 * root + 2);
		dfs(2 * root + 1);
		if(root * 2 + 1 > n && root * 2 + 2 > n) {
			for(int i = 0; i < tmp.size(); ++i) {
				printf("%d%s", tmp[i], i == tmp.size() - 1 ? "\n" : " ");
			}
		}
		tmp.pop_back();
	}
}
void judge() {
	flag1 = flag2 = true;
	for(int i = 0; i < n / 2 && (flag1 || flag2); ++i) {
		if((i * 2 + 1 < n && levelorder[i] < levelorder[i * 2 + 1]) || (i * 2 + 2 < n && levelorder[i] < levelorder[i * 2 + 2])) flag1 = false;
		if((i * 2 + 1 < n && levelorder[i] > levelorder[i * 2 + 1]) || (i * 2 + 2 < n && levelorder[i] > levelorder[i * 2 + 2])) flag2 = false;
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	scanf("%d", &n);                          
	int i, j;
	for(i = 0; i < n; ++i) scanf("%d", levelorder + i);
	dfs(0);
	judge();
 	if(!flag1 && !flag2) printf("Not Heap\n");
 	else if(flag1) printf("Max Heap\n");
 	else if(flag2) printf("Min Heap\n");
 	return 0;
} 
