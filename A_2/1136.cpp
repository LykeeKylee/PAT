#include<bits/stdc++.h>
using namespace std;
bool judge(string &s, int i, int len) {
	if(i > len - i - 1) return true;
	return s[i] == s[len - i - 1] && judge(s, i + 1, len);
}
bool judge(string &s) {
	int len = s.length();
	for(int i = 0; i < len; ++i) {
		if(s[i] != s[len - i - 1])
			return false;
	}
	return true;
}
string add(string &a, string &b) {
	string c;
	int len = a.length(), flag = 0;
	for(int i = len - 1; i >= 0; --i) {
		int x = a[i] + b[i] - 2 * '0' + flag;
		c = char('0' + x % 10) + c;
		flag = x / 10;
	}
	if(flag != 0)
		c = char(flag + '0') + c;
	return c;
}
int main() {
	string a, b, c;
	int i;
	cin >> a;
	if(!judge(a)) {
		for(i = 0; i < 10; ++i) {
			b = a;
			reverse(b.begin(), b.end());
			c = add(a, b);
			printf("%s + %s = %s\n", a.c_str(), b.c_str(), c.c_str());
			a = c;
			if(judge(c)) break;
		}
	}
	if(i < 10) printf("%s is a palindromic number.\n", a.c_str());
	else printf("Not found in 10 iterations.\n");
	return 0;
}
