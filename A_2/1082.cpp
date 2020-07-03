#include<bits/stdc++.h>
using namespace std;
int n;
string num, ans, digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"}, place[4] = {"", " Shi", " Bai", " Qian"};
string convert(string &sub) {
	int i, j;
	string ret;
	for(i = 0; i < sub.length(); ++i) {
		if(sub[i] == '0') {
			if(i + 1 < sub.length() && sub[i + 1] != '0')
				ret = ret + " " + digit[0];
		} else {
			ret = ret + " " + digit[sub[i] - '0'] + place[sub.length() - 1 - i];
		}
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif
	int i, j;
	bool flag;
	scanf("%d", &n);
	flag = n < 0 ? true: false;
	n = abs(n);
	num = to_string(n);
	if(num == "0") ans = " ling";
	else {
		int cnt = 0;
		for(i = num.length() - 1, j = 0; i >= 0; --i) {
			++j;
			if(j == 4 || i == 0) {
				++cnt;
				string sub = num.substr(i, j);
				ans = convert(sub) + ans;
				if(i != 0) {
					if(cnt == 1 ) ans = " Wan" + ans;
					else if(cnt == 2) ans = " Yi" + ans;
				}
				j = 0;
			}
		}
	}
	if(flag) printf("%s%s", "Fu", ans.c_str());
	else printf("%s", ans.substr(1, ans.length() - 1).c_str());
	return 0;
}
