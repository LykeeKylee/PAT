#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k, i, j, d1, d2, query[1005], safe = 1;
	cin >> n >> m;
	map<int, vector<int> > dangerous;
	for(i = 0; i < n; ++i) {
		cin >> d1 >> d2;
		dangerous[d1].push_back(d2);
		dangerous[d2].push_back(d1);
	}
	for(i = 0; i < m; ++i) {
		cin >> k;
		safe = 1;
		for(j = 0; j < k; ++j) cin >> query[j];
		for(j = 0; j < k && safe == 1; ++j) {
			map<int, vector<int> >::iterator exist = dangerous.find(query[j]);
			if(exist == dangerous.end()) continue;
			vector<int> *ptr = &dangerous[query[j]];
			for(int l = j + 1; l < k && safe == 1; ++l) {
				if(find(ptr->begin(), ptr->end(), query[l]) != ptr->end()) safe = 0;
			}
		}
		if(safe == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
