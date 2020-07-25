#include<bits/stdc++.h>
using namespace std;
struct node {
	char c;
	int nextNode;
	bool flag = false;
};
int head1, head2, n;
node nodeList[100005]; 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	scanf("%d %d %d", &head1, &head2, &n);
	for(i = 0; i < n; ++i) {
		int address, nextNode;
		char c;
		scanf("%d %c %d", &address, &c, &nextNode);
		nodeList[address].c = c;
		nodeList[address].nextNode = nextNode;
	}
	i = head1;
	while(i != -1) {
		nodeList[i].flag = true;
		i = nodeList[i].nextNode;
	}
	int pos = -1;
	i = head2;
	while(i != -1) {
		if(nodeList[i].flag) {
			pos = i;
			break;
		}
		i = nodeList[i].nextNode;
	}
	if(pos == -1) printf("-1");
	else printf("%05d", pos);
	return 0;
}
