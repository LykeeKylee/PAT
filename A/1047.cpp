#include<bits/stdc++.h>
using namespace std;
vector<string> courses[2505];
int main() {
	int n, k, i, j, c, x;
	string name;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; ++i) {
		cin >> name;
		scanf("%d", &c);
		for(j = 0; j < c; ++j) {
			scanf("%d", &x);
			courses[x].emplace_back(name);
		}
	}
	for(i = 1; i <= k; ++i) {
		printf("%d %d\n", i, courses[i].size());
		sort(courses[i].begin(), courses[i].end());
		for(j = 0; j < courses[i].size(); ++j) printf("%s\n", courses[i][j].c_str());
	}
	return 0;
} 
