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
	vector<node> neg, low, high, nodeList;
	i = head;
	while(i != -1) {
		if(memory[i].value < 0) neg.push_back(memory[i]);
		else if(memory[i].value <= k) low.push_back(memory[i]);
		else high.push_back(memory[i]);
		i = memory[i].nextNode;
	}
	nodeList.insert(nodeList.end(), neg.begin(), neg.end());
	nodeList.insert(nodeList.end(), low.begin(), low.end());
	nodeList.insert(nodeList.end(), high.begin(), high.end());
	for(i = 0; i < nodeList.size(); ++i) {
		if(i != nodeList.size() - 1) printf("%05d %d %05d\n", nodeList[i].address, nodeList[i].value, nodeList[i + 1].address);
		else printf("%05d %d -1\n", nodeList[i].address, nodeList[i].value);
	}
	return 0;
}
