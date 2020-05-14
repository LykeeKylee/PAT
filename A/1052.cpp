#include<bits/stdc++.h>
using namespace std;
struct node {
	int address, data;
};
bool cmp(node &a, node &b) {
	return a.data < b.data;
}
int data[100005], next_[100005];
int main() {
	int n, head, i, j, p;
	scanf("%d %d", &n, &head);
	for(i = 0; i < n; ++i) {
		scanf("%d", &j);
		scanf("%d %d", data + j, next_ + j);
	}
	p = head;
	vector<node> v;
	while(p != -1) {
		node tmp{p, data[p]};
		v.emplace_back(tmp);
		p = next_[p];
	}
	sort(v.begin(), v.end(), cmp);
	if(!v.empty()) printf("%d %05d\n", v.size(), v[0].address);
	else printf("0 -1\n");
	for(i = 0; i < v.size(); ++i) {
		if(i != v.size() - 1) printf("%05d %d %05d\n", v[i].address, v[i].data, v[i + 1].address);
		else printf("%05d %d -1\n", v[i].address, v[i].data);
	}
	return 0;
}
