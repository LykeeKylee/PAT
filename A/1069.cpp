#include<bits/stdc++.h>
using namespace std;
int main() {
	string x, xx;
	int ans;
	getline(cin, x);
	do {
		while(x.length() < 4) x += '0';
		sort(x.begin(), x.end());
		xx = x;
		reverse(xx.begin(), xx.end());
		ans = stoi(xx, nullptr) - stoi(x, nullptr);
		printf("%s - %s = %04d\n", xx.c_str(), x.c_str(), ans);
		x = to_string(ans);
	} while(ans != 6174 && ans != 0);
	return 0;
}
