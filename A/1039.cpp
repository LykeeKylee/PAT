#include<bits/stdc++.h>
using namespace std;
unordered_map<int, set<int>> clist;
char nn[5];

////Hash 
//int getid(char *name) {
//    int id = 0;
//    for(int i = 0; i < 3; i++)
//        id = 26 * id + (name[i] - 'A');
//    id = id * 10 + (name[3] - '0');
//    return id;
//}
//const int maxn = 26 * 26 * 26 * 10 + 10;
//vector<int> v[maxn];

int main() {
	int n, k, i, j, id, ni;
	scanf("%d %d", &n, &k);
	for(i = 0; i < k; ++i) {
		scanf("%d %d", &id, &ni);
		for(j = 0; j < ni; ++j) {
			scanf("%s", nn);
			string name(nn, nn + 4);
			clist[name].insert(id);
		}
	}
	for(i = 0; i < n; ++i) {
		scanf("%s", nn);
		string name(nn, nn + 4);
		printf("%s", name.c_str());
		set<int> *p = &clist[name];
		printf(" %d", p->size());
		for(auto m = p->begin(); m != p->end(); ++m) printf(" %d", *m);
		printf("\n");
	}
	return 0;
}
