#include<bits/stdc++.h>
using namespace std;
bool isprime(int x) {
	if(x < 2) return false;
	int upper = (int)(sqrt(1.0 * x));
	for(int i = 2; i <= upper; ++i)
		if(x % i == 0)
			return false;
	return true;
}
bool judge(int n, int d) {
	vector<int> remain;
	int r = 0;
	while(n > 0) {
		remain.push_back(n % d);
		n /= d;
	}
	for(int i = remain.size() - 1; i >= 0; --i)
		r += remain[i] * pow(d, remain.size() - i - 1);
	return isprime(r);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n, d;
	while(cin >> n) {
		if(n < 0) break;
		cin >> d;
		printf("%s\n", (isprime(n) && judge(n, d)) ? "Yes" : "No");
	}
	return 0;
}
