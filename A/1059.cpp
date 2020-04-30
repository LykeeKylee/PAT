#include<bits/stdc++.h>
using namespace std;
bool isprime(long long x) {
	if(x == 0 || x == 1) return false;
	else if(x == 2) return true;
	else if(x % 2 == 0) return false;
	int upper = (int)sqrt(x);
	for(int i = 3; i <= upper; i += 2) {
		if(x % i == 0) return false;
	}
	return true;
}
int main() {
	long long n, i = 2, cnt;
	scanf("%lld", &n); 
	printf("%lld=", n);
	bool flag = false;
	if(n == 1) cout << 1 << endl;
	while(n != 1) {
		if(isprime(i)) {
			if(n % i == 0) {
				cnt = 0;
				while(n % i == 0) {
					n /= i;
					++cnt;
				}
				printf("%s", flag ? "*" : "");
				flag = true;
				if(cnt == 1) printf("%d", i);
				else printf("%d^%d", i, cnt);
			}
		}
		++i;
	}
	return 0;
}
