#include <bits/stdc++.h>
using namespace std;
bool is_pali(string &str) {
	int len = str.length();
	for(int i = 0; i <= len / 2; ++i) {
		if(str[i] != str[len - i - 1]) return false;
	}
	return true;
}
string add(string &a, string &b) {
	string ret;
	int flag = 0;
	auto i = a.rbegin(), j = b.rbegin();
	for(;i != a.rend() && j != b.rend(); ++i, ++j) {
		int x = int(*i + *j - 2 * '0') + flag;
		ret = char(x % 10 + '0') + ret;
		flag = x / 10;
	}
	if(flag != 0) ret = char(flag + '0') + ret;
	return ret;
}
int main() {
	string s;
	getline(cin, s);
	if(is_pali(s)) printf("%s is a palindromic number.", s.c_str());
	else {
		bool findx = false;
		for(int i = 0; i < 10; ++i) {
			string rs = s, ret;
			reverse(rs.begin(), rs.end());
			ret = add(s, rs);
			printf("%s + %s = %s\n", s.c_str(), rs.c_str(), ret.c_str());
			s = ret;
			if(is_pali(s)) {
				findx = true;
				break;
			}
		}
		if(findx) printf("%s is a palindromic number.", s.c_str());
		else printf("Not found in 10 iterations.");
	}
	return 0;
}
