#include<bits/stdc++.h>
using namespace std;
struct node {
	int address;
	int value;
	int nextNode;
};
bool cmp(node &a, node &b) {
	return a.value < b.value;
}
int n, head;
node memory[100005];
vector<node> nodeList;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d", &n, &head);
	for(i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		memory[a].address = a;
		memory[a].value = b;
		memory[a].nextNode = c;
	}
	i = head;
	while(i != -1) {
		nodeList.push_back(memory[i]);
		i = memory[i].nextNode;
	}
	sort(nodeList.begin(), nodeList.end(), cmp);
	if(nodeList.size() > 0) printf("%d %05d\n", nodeList.size(), nodeList.front().address);
	else printf("0 -1");
	for(i = 0; i < nodeList.size(); ++i) {
		printf("%05d %d ", nodeList[i].address, nodeList[i].value);
		if(i + 1 < nodeList.size()) printf("%05d\n", nodeList[i + 1].address);
		else printf("-1\n");
	}
	return 0;
}
