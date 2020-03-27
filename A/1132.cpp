#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool cal(string z) {
	ll a, b, c, len = z.length();
	a = stoll(z, nullptr);
	b = stoll(z.substr(0, len / 2), nullptr);
	c = stoll(z.substr(len / 2, len / 2), nullptr);
	if(b == 0 || c == 0) return false;
	return a % (b * c) == 0;
}
int main() {
	int n, i;
	string z;
	scanf("%d", &n);
	getchar();
	for(i = 0; i < n; ++i) {
		getline(cin, z);
		if(cal(z)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
