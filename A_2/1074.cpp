#include<bits/stdc++.h>
using namespace std;
struct node {
	int address;
	int value;
	int nextNode;
};
int head, n, k;
node memory[100005];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d %d", &head, &n, &k);
	for(i = 0; i < n; ++i) {
		int address;
		scanf("%d", &address);
		memory[address].address = address;
		scanf("%d %d", &memory[address].value, &memory[address].nextNode);
	}
	vector<node> nodeList;
	i = head;
	while(i != -1) {
		nodeList.push_back(memory[i]);
		i = memory[i].nextNode;
	}
	for(i = 0; i < nodeList.size(); i += k) {
		if(i + k <= nodeList.size())
			reverse(nodeList.begin() + i, nodeList.begin() + i + k);
	}
	for(i = 0; i < nodeList.size(); ++i) {
		if(i != nodeList.size() - 1) printf("%05d %d %05d\n", nodeList[i].address, nodeList[i].value, nodeList[i + 1].address);
		else printf("%05d %d -1\n", nodeList[i].address, nodeList[i].value);
	}
	return 0;
}
