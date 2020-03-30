#include<bits/stdc++.h>
using namespace std;
struct item {
	int id;
	int freq;
};
bool cmp(item* a, item* b) {
	if(a->freq != b->freq) return a->freq > b->freq;
	else return a->id < b->id;
}
item query[50005];
bool visit[50005];
int main() {
	int n, k, i, j, q, cnt = 0;
	vector<item*> ptr;
	fill(visit, visit + 50005, false);
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; ++i) {
		scanf("%d", &q);
		sort(ptr.begin(), ptr.end(), cmp);
		if(i != 0) {
			printf("%d:", q);
			for(j = 0; j < k && j < ptr.size(); ++j) printf(" %d", ptr[j]->id);
			printf("\n");
		}
		++query[q].freq;
		query[q].id = q;
		if(!visit[q] && ptr.size() < k) {
			ptr.emplace_back(&query[q]);
			visit[q] = true;
		}
		else {
			if(!visit[q] && ((query[q].freq > ptr[k - 1]->freq) || (query[q].freq == ptr[k - 1]->freq && query[q].id < ptr[k - 1]->id))) {
				visit[ptr[k - 1]->id] = false;
				visit[q] = true;
				ptr[k - 1] = &query[q];
			}
		} 
	}
	return 0;
}
