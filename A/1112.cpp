#include <bits/stdc++.h>
using namespace std;
set<char> error, tmp;
bool check[256];
int main() {
	int k, i = 0, j, len;
	string str;
	cin >> k >> str;
	while(i < str.length()) {
		int key = i++, cnt;
		while(i < str.length() && str[i] == str[key]) ++i;
		cnt = i - key;
		if(cnt % k != 0) {
			check[str[key]] = true;
			error.erase(str[key]);
		}
		else if(!check[str[key]]) error.insert(str[key]);
	}
	tmp = error;
	for(auto s = str.begin(); s != str.end(); ++s) {
		if(tmp.find(*s) != tmp.end()) {
			printf("%c", *s);
			tmp.erase(*s);
		}
	}
	printf("\n");
	for(i = 0; i < str.length(); ++i) {
		printf("%c", str[i]);
		if(error.find(str[i]) != error.end()) i += (k - 1);
	}
	return 0;
}
