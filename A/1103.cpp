#include<bits/stdc++.h>
using namespace std;
int maxCnt = -1;
vector<int> tmp(402), ret(402);
int powmap[402], smap[402];
void init(int n, double p) {
	int i, j;
	i = 1;
	j = int(pow(i, p));
	while(j <= n) {
		powmap[i] = j;
		++i;
		j = int(pow(i, p));
	}
	for(i = 1; i <= n; ++i) smap[i] = int(pow(i, 1.0 / p));
}
void cal(int n, int k, double p, int mk, int cnt, int pre) {
	int root = smap[n];
	if(k == mk) {
		if(powmap[root] == n) {
			cnt += root;
			tmp[k] = root;
			if(maxCnt < cnt) {
				maxCnt = cnt;
				ret = tmp;
			} else if(maxCnt == cnt) {
				bool flag = true;
				for(int j = 1; j <= mk; ++j) {
					if(tmp[j] < ret[j]) {
						flag = false;
						break;
					} else if(tmp[j] > ret[j]) break;
				}
				if(flag) {
					maxCnt = cnt;
					ret = tmp;
				}
			}
		}
		return;
	}
	int start = powmap[root] == n ? root - 1 : root;
	start = start > pre ? pre : start;
	for(int i = start; i >= 1; --i) {
		tmp[k] = i;
		if(n - powmap[i] == 0) continue;
		cal(n - powmap[i], k + 1, p, mk, cnt + i, i);
	}
}
int main() {
	int n, k, i, j;
	double p;
	scanf("%d %d %lf", &n, &k, &p);
//	clock_t t1 = clock();
	init(n, p);
	cal(n, 1, p, k, 0, 999999999);
	if(maxCnt == -1) printf("Impossible\n");
	else {
		printf("%d", n);
		for(i = 1; i <= k; ++i) printf("%s%d%s%d%s", (i == 1) ? " = " : " + ", ret[i], "^", int(p), (i == k) ? "\n":"");
	}
//	clock_t t2 = clock();
//	cout << t2 - t1 << endl; // 400 400 2: 1012ms
	return 0;
}
