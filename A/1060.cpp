#include<bits/stdc++.h>
using namespace std;
string convert(string &a, int n) {
	int i, pos;
	string ret;
	for(i = 0; i < a.length(); ++i) {
		if(a[i] != '0') break;
	}
	// a <= 0
	if(a[i] == '.') {
		a = a.substr(i + 1, a.length() - i - 1);
		pos = 0;
		for(pos = 0; pos < a.length(); ++pos) {
			if(a[pos] != '0') break;
		}
		if(pos == a.length()) {
			ret = "0.";
			ret.insert(ret.end(), n, '0');
			ret += "*10^0";
		} else {
			a = a.substr(pos, a.length() - pos);
			if(a.length() < n) a.insert(a.end(), n - a.length(), '0');
			ret = "0." + a.substr(0, n) + "*10^" + (pos > 0 ? "-" : "") + to_string(pos);
		}
	}
	// a > 0
	else {
		a = a.substr(i, a.length() - i);
		for(pos = 0; pos < a.length(); ++pos) {
			if(a[pos] == '.') break;
		}
		// 12300
		if(pos != a.length()) a.erase(a.begin() + pos);
		if(a.length() < n) a.insert(a.end(), n - a.length(), '0');
		ret = "0." + a.substr(0, n) + "*10^" + to_string(pos);
	}
	return ret;
}
int main() {
	int n, i, j;
	string a, b;
	cin >> n >> a >> b;
	a = convert(a, n);
	b = convert(b, n);
	if(a == b) cout << "YES" << ' ' << a << endl;
	else cout << "NO" << ' ' << a << ' ' << b << endl;
	return 0;
}
