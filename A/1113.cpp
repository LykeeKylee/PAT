#include <bits/stdc++.h>
using namespace std;
long long sum(int a, int b, vector<long long> &v) {
	long long sum = 0;
	for(int i = a; i <= b; ++i) sum += v[i];
	return sum;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	vector<long long> a(n);
	for(i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	long long s1 = sum(0, n / 2 - 1, a), s2 = sum(n / 2, n - 1, a);
	cout << n % 2 << ' ' << abs(s1 - s2);
	return 0;
}
