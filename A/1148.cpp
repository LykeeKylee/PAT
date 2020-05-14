#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j, k, result[105], predict[105], findx = 0;
	cin >> n;
	for(i = 1; i <= n; ++i) cin >> predict[i];
	for(i = 1; i <= n && findx == 0; ++i) {
		for(j = i + 1; j <= n && findx == 0; ++j) {
			vector<int> lier;
			fill(result, result + 105, 1);
			result[i] = result[j] = -1;
			for(k = 1; k <= n; ++k) {
				if(predict[k] * result[abs(predict[k])] < 0) lier.push_back(k);
			}
			if(lier.size() == 2 && result[lier[0]] + result[lier[1]] == 0) {
				cout << i << ' ' << j;
				findx = 1;
			}
		}
	}
	if(findx == 0) cout << "No Solution";
	return 0;
}
