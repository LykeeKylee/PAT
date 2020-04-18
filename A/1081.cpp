#include<bits/stdc++.h>
using namespace std;
long long gcd(long a, long b) {
	if(a < b) swap(a, b);
	return b == 0 ? a : gcd(a % b, b);
}
string convert(int a, int b) {
	string ret;
	if(a == 0) ret = "0";
	else if(b == 0) ret = "Inf";
	else {
		string sign = ((a < 0 && b > 0) || (a > 0 && b < 0)) ? "-" : "";
		a = abs(a);
		b = abs(b);
		int z = a / b;
		if(z != 0) ret += to_string(z);
		a %= b;
		if(a != 0) {
			if(z != 0) ret += " ";
			ret += (to_string(a) + "/" + to_string(b));
		}
		ret = sign + ret;
	}
	return ret;
}
int main() {
	int n, i;
	long long a, b, suma = -1, sumb = -1;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%lld/%lld", &a, &b);
		if(sumb == -1) {
			suma = a;
			sumb = b;
		}
		else {
			suma = suma * b + a * sumb;
			sumb *= b;
		}
		int sign = suma < 0 ? -1 : 1;
		suma = abs(suma);
		int k = gcd(suma, sumb);
		suma = suma / k * sign;
		sumb = sumb / k;
	}
	string ret = convert(suma, sumb);
	printf("%s\n", ret.c_str());
	return 0;
}
