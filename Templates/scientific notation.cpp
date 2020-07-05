#include<bits/stdc++.h>
using namespace std;
string convert(string a) {
	int dot = find(a.begin(), a.end(), '.') - a.begin(), pos = 0;
	string ret;
	while(a[pos] == '0' || a[pos] == '.') ++pos;
	if(pos == a.length()) {
		ret = "";
		ret = "0.0" + ret + "*10^0";
	}
	else {
		if(dot > pos && dot != a.length()) a.erase(dot, 1);
		ret = a.substr(pos, a.length() - pos);
		ret.insert(1, 1, '.');
		if(dot < pos) ret = ret + "*10^" + to_string(dot - pos);
		else ret = ret + "*10^" + to_string(dot - pos - 1);
	}
	return ret;
}
int main() {
	string a;
	cin >> a;
	cout << convert(a) << endl;
	return 0;
}
