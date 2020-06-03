#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll binarypow1(ll a, ll b) {
	if(!b) return 1;
	if(b & 1) return a * binarypow1(a, b - 1);
	else {
		int x = binarypow1(a, b >> 1);
		return x * x;
	}
}
ll binarypow2(ll a, ll b) {
	int ans = 1;
	while(b > 0) {
		cout << b << ' ' << a << ' ' << ans << endl;
		if(b & 1) 
			ans *= a;
		a *= a;
		b >>= 1;
	} 
	return ans;
}
int main() {
	int a = 2, b = 3;
	cout << binarypow1(2, 10) << endl;
	cout << binarypow2(2, 10) << endl;
	return 0;
}
