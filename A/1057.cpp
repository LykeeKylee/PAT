#include<bits/stdc++.h>
using namespace std;
const int msize = 100005;
int c[msize];
int lowbit(int x) {
	return x & (-x);
}
void update(int x, int y) {
	for(int i = x; i < msize; i += lowbit(i)) c[i] += y;
}
int getsum(int x) {
	int sum = 0;
	for(int i = x; i >= 1; i -= lowbit(i)) sum += c[i];
	return sum;
}
int main() {

	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif

	int n, i, top = 0, key, mid;
	stack<int> s;
	char cmd[20];
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%s", cmd);
		if(strlen(cmd) == 4) {
			scanf("%d", &key);
			s.push(key);
			update(key, 1);
		} else if(strlen(cmd) == 3) {
			if(s.empty()) printf("Invalid\n");
			else {
				printf("%d\n", s.top());
				update(s.top(), -1);
				s.pop();
			}
		} else {
			if(s.empty()) printf("Invalid\n");
			else {
				int left = 1, right = msize, mid, k = (s.size() + 1) / 2, midsum;
				while(left < right) {
					mid = (left + right) / 2;
					midsum = getsum(mid);
					if(midsum >= k) right = mid;
					else if(midsum < k) left = mid + 1;
				}
				printf("%d\n", left);
			}
		}
	}
	return 0;
}
