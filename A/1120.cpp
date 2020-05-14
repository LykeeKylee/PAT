#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j, x, cnt;
	set<int> friendID;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &x);
		cnt = 0;
		while(x != 0) {
			cnt += x%10;
			x /= 10;
		}
		friendID.insert(cnt);
	}
	cout << friendID.size() << endl;
	for(auto f = friendID.begin(); f != friendID.end(); ++f) 
		printf("%s%d", (f == friendID.begin() ? "": " "), *f);
	return 0;
}
