#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, left, right;
};
int num[1005], n, cbt[1005], idx = 0;
vector<node> bst;
//int create(int low, int high) {
//	node tmp {};
//	if(low > high) return -1;
//	int size = high - low + 1, level = int(ceil(log(high - low + 2) / log(2))), remains, mid;
//	remains = size - int(pow(2, level - 1)) + 1;
//	if(remains >= int(pow(2, level - 2))) mid = low + int(pow(2, level - 1)) - 1;
//	else mid = low + remains + int(pow(2, level - 2)) - 1;  
//	tmp.x = num[mid];
//	tmp.left = create(low, mid - 1);
//	tmp.right = create(mid + 1, high);
//	bst.emplace_back(tmp);
//	return bst.size() - 1;
//}
void better(int root) {
	if(root * 2 + 1 <= n - 1) better(root * 2 + 1);
	cbt[root] = num[idx++];
	if(root * 2 + 2 <= n - 1) better(root * 2 + 2);
} 
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", num + i);
	sort(num, num + n);
	better(0);
	for(i = 0; i < n; ++i) printf("%s%d", i == 0 ? "" : " ", cbt[i]);
	
//	queue<int> q;
//	q.push(create(0, n - 1));
//	bool flag = true;
//	while(!q.empty()) {
//		int front = q.front();
//		q.pop();
//		printf("%s%d", !flag ? " ":"", bst[front].x);
//		flag = false;
//		if(bst[front].left != -1) q.push(bst[front].left);
//		if(bst[front].right != -1) q.push(bst[front].right);
//	}
	return 0;
}
