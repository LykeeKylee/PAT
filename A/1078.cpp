#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x) {
	if(x == 0 || x == 1) return false;
	else if(x == 2) return true;
	else if(x % 2 == 0) return false;
	int upper = int(sqrt(x));
	for(int i = 3; i <= upper; i += 2) {
		if(x % i == 0) return false;
	}
	return true;
}
int x[10005];
int main() {
	int msize, n, i;
	scanf("%d %d", &msize, &n);
	while(!is_prime(msize)) ++msize;
	vector<bool> visit(msize, false);
	map<int, int> pos;
	for(i = 0; i < n; ++i) scanf("%d", x + i);
	for(i = 0; i < n; ++i) {
		int step = 0, halfsize = msize / 2;
		while(step <= halfsize) {
			int p = (x[i] + step * step) % msize;
			if(!visit[p]) {
				visit[p] = true;
				pos[x[i]] = p;
				break; 
			}
			++step;
		}
		if(step > halfsize) pos[x[i]] = -1;
	}
	for(i = 0; i < n; ++i) {
		if(pos[x[i]] == -1) printf("-");
		else printf("%d", pos[x[i]]);
		printf("%s", i == n - 1 ? "\n": " ");
	}
	return 0;
}
