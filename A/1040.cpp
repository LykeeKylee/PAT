#include<bits/stdc++.h>
using namespace std;
int main() {
	int i, j, maxlen = -1, slen, len;
	string s;
	getline(cin, s);
	slen = s.length();
	for(i = 0; i < slen; ++i) {
		if(i == slen - 1 || s[i] != s[i + 1]) {
			j = 1;
			len = 1;
			while(i + j < slen && i - j >= 0 && s[i + j] == s[i - j]) {
				len += 2;
				++j;
			}
		}
		else {
			j = 0;
			len = 0;
			while(i - j >= 0 && i + 1 + j < slen && s[i - j] == s[i + 1 + j]) {
				len += 2;
				++j;
			}
		}
		maxlen = len > maxlen ? len : maxlen;
	}
	printf("%d\n", maxlen);
	return 0;
}
