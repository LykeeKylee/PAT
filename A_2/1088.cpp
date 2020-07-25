#include<bits/stdc++.h>
using namespace std;
long long a1, b1, a2, b2;
long long gcd(long long a, long long b) {
	if(a < b) swap(a, b);
	return a % b == 0 ? b : gcd(a % b, b);
}
string convert(long long a, long long b) {
	if(b == 0) return "Inf";
	else if(a == 0) return "0";
	
	long long sign;
	if((a > 0 && b > 0) || (a < 0 && b < 0)) sign = 1;
	else sign = -1;
	a = abs(a);
	b = abs(b);
	long long c = gcd(a, b);
	a /= c;
	b /= c;
	long long z = a / b;
	a %= b;
	string ret;
	if(z != 0) ret += to_string(z);
	if(a != 0) {
		if(z != 0) ret += " ";
		ret = ret + to_string(a) + "/" + to_string(b);
	}
	if(sign == -1) ret = "(-" + ret + ")";
	return ret;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	string as = convert(a1, b1), bs = convert(a2, b2);
	printf("%s + %s = %s\n", as.c_str(), bs.c_str(), convert(a1 * b2 + a2 * b1, b1 * b2).c_str());
	printf("%s - %s = %s\n", as.c_str(), bs.c_str(), convert(a1 * b2 - a2 * b1, b1 * b2).c_str());
	printf("%s * %s = %s\n", as.c_str(), bs.c_str(), convert(a1 * a2, b1 * b2).c_str());
	printf("%s / %s = %s\n", as.c_str(), bs.c_str(), convert(a1 * b2, b1 * a2).c_str());
	return 0;
} 
