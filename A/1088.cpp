#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
	if(a < b) swap(a, b);
	return b == 0 ? a : gcd(a % b, b);
}
string simplify(long long a, long long b) {
	string ret;
	if(a == 0) ret = "0";
	else if(b == 0) ret = "Inf";
	else {
		int sign = ((a > 0 && b < 0) || (a < 0 && b > 0)) ? -1 : 1, g, z, f;
		a = abs(a);
		b = abs(b);
		g = gcd(a, b);
		a /= g;
		b /= g;
		z = a / b;
		f = a % b;
		if(z != 0) ret += to_string(z);
		if(f != 0) {
			if(z != 0) ret += " ";
			ret += to_string(f);
			ret += "/";
			ret += to_string(b);
		}
		if(sign == -1) ret = "(-" + ret + ")";
	}
	return ret;
}
int main() {
	long long a1, b1, a2, b2, a, b;
	string as, bs, ret;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	as = simplify(a1, b1);
	bs = simplify(a2, b2);
	printf("%s + %s = %s\n", as.c_str(), bs.c_str(), simplify(a1 * b2 + a2 * b1, b1 * b2).c_str());
	printf("%s - %s = %s\n", as.c_str(), bs.c_str(), simplify(a1 * b2 - a2 * b1, b1 * b2).c_str());
	printf("%s * %s = %s\n", as.c_str(), bs.c_str(), simplify(a1 * a2, b1 * b2).c_str());
	printf("%s / %s = %s\n", as.c_str(), bs.c_str(), simplify(a1 * b2, a2 * b1).c_str());
	return 0;
}
