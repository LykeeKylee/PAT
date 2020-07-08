#include<bits/stdc++.h>
using namespace std;
string n;
int k;
bool judge(string &s) {
	int i = 0, len = s.length();
	while(i <= len - 1 - i) {
		if(s[i] != s[len - 1 - i])
			return false;
		++i;
	}
	return true;
}
string add(string a) {
	string b = a, c;
	reverse(b.begin(), b.end());
	int flag = 0;
	for(int i = a.length() - 1; i >= 0; --i) {
		int x = a[i] + b[i] - 2 * '0' + flag;
		c = char('0' + x % 10) + c;
		flag = x / 10;
	}
	if(flag != 0) c = "1" + c;
	return c;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	cin >> n >> k;
	int i = 0;
	while(i < k && !judge(n)) {
		++i;
		n = add(n);
	}
	printf("%s\n%d", n.c_str(), i);
	return 0;
}
