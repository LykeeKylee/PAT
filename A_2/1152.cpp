#include<bits/stdc++.h>
using namespace std;
bool isprime(int n) {
	if(n < 2) return false;
	int upper = (int)(sqrt(1. * n));
	for(int i = 2; i <= upper; ++i) {
		if(n % i == 0) return false;
	}
	return true;
}
int main() {
	#ifndef ONLINE_JUDGE;
	freopen("data.txt", "r", stdin);
	#endif
	int l, k, i = 0;
	bool flag = false;
	char str[1005];
	scanf("%d %d", &l, &k);
	scanf("%s", str);
	while(str[i] == '0') ++i;
	for(; i < l - k + 1; ++i) {
		string subs(str + i, str + i + k);
		int num = atoi(subs.c_str());
		if(isprime(num)) {
			printf("%s\n", subs.c_str());
			flag = true;
			break;
		}
	}
	if(!flag) printf("404\n");
	return 0;
}
