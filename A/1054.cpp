#include<bits/stdc++.h>
using namespace std;
int maps[800][600];
map<int, int> colorcnt;
int main() {
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	for(i = 0; i < n; ++i) {
		for(j = 0; j < m; ++j) {
			scanf("%d", &maps[i][j]);
			++colorcnt[maps[i][j]];
		}
	}
	i = j = -1;
	for(auto c = colorcnt.begin(); c != colorcnt.end(); ++c) {
		if(c->second > j) {
			i = c->first;
			j = c->second;
		}
	}
	cout << i << endl;
	return 0;
}
