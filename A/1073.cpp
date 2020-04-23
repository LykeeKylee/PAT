#include<bits/stdc++.h>
using namespace std;
int main() {
	string sci, integer, ans;
	int len;
	getline(cin, sci);
	char flag = sci[0];
	string::size_type E = sci.find('E'), dot = sci.find('.');
	int exp = stoi(sci.substr(E + 1, sci.length() - E  - 1).c_str(), nullptr);
	integer = sci.substr(1, E - 1);
	if(exp == 0) ans = integer;
	else if(exp > 0) {
		len = integer.length() - 2;
		if(len <= exp) integer.insert(integer.length(), exp - len, '0');
		else integer.insert(exp + 2, 1, '.');
		integer.erase(1, 1);
		ans = integer;
	}
	else {
		exp = abs(exp);
		integer.erase(1, 1);
		integer.insert(0, exp - 1, '0');
		ans = "0." + integer;
	}
	ans = flag == '-' ? "-" + ans : ans;
	cout << ans << endl;
	return 0;
}
