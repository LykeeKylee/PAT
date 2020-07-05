#include<bits/stdc++.h>
using namespace std;
int n;
string a, b;
string convert(string a) {
	int dot = find(a.begin(), a.end(), '.') - a.begin(), pos = 0;
	string ret;
	while(a[pos] == '0' || a[pos] == '.') ++pos;
	if(pos == a.length()) {
		ret = "";
		ret.insert(ret.begin(), n, '0');
		ret = "0." + ret + "*10^0";
	}
	else {
		if(dot > pos && dot != a.length()) a.erase(dot, 1);
		ret = a.substr(pos, a.length() - pos);
		if(ret.length() < n) ret.insert(ret.end(), n - ret.length(), '0');
		if(dot < pos) ret = "0." + ret.substr(0, n) + "*10^" + to_string(dot - pos + 1);
		else ret = "0." + ret.substr(0, n) + "*10^" + to_string(dot - pos);
	}
	return ret;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	cin >> n >> a >> b;
	string as = convert(a), bs = convert(b); 
	if(as == bs) printf("YES %s", as.c_str());
	else printf("NO %s %s", as.c_str(), bs.c_str());
	return 0;
}
