#include <bits/stdc++.h>
using namespace std;
int main() {
	int d, n, i, j;
	cin >> d >> n;
	string ret = to_string(d);
	for(i = 2; i <= n; ++i) {
		string tmp;
		char c = ret[0];
		int cnt = 0, len = ret.length();
		for(j = 0; j < len; ++j) {
			if(c != ret[j]) {
				tmp += (c + to_string(cnt));
				c = ret[j];
				cnt = 1;
			} else ++cnt;
		}
		tmp += (c + to_string(cnt));
		ret = tmp;
	}
	cout << ret << endl;
	return 0;
}
