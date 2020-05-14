#include <bits/stdc++.h>
using namespace std;
int main() {
	int head, n, k, i, j, data[100005], nextd[100005];
	vector<int> a, b, c;
	scanf("%d %d %d", &head, &n, &k);
	for(i = 0; i < n; ++i) {
		int ad, num, nx;
		scanf("%d %d %d", &ad, &num, &nx);
		data[ad] = num;
		nextd[ad] = nx;
	}
	i = head;
	while(i != -1) {
		if(data[i] < 0) a.emplace_back(i);
		else if(data[i] <= k) b.emplace_back(i);
		else c.emplace_back(i);
		i = nextd[i];
	}
	a.insert(a.end(), b.begin(), b.end());
	a.insert(a.end(), c.begin(), c.end());
	for(i = 0; i < a.size(); ++i) {
		if(i != a.size() - 1) printf("%05d %d %05d\n", a[i], data[a[i]], a[i+1]);
		else printf("%05d %d -1", a[i], data[a[i]]);
	}
	return 0;
}
