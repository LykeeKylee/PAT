#include<bits/stdc++.h>
using namespace std;
map<int, int> cnt1, cnt2;
int main() {
	string buy, target;
	int i, missing = 0;
	getline(cin, buy);
	getline(cin, target);
	for(i = 0; i < target.length(); ++i) ++cnt1[target[i]];
	for(i = 0; i < buy.length(); ++i) ++cnt2[buy[i]];
	bool okay = true;
	for(auto m = cnt1.begin(); m != cnt1.end(); ++m) {
		if(m->second > cnt2[m->first]) okay = false;
		missing += max(0, m->second - cnt2[m->first]);
	}
	printf("%s %d\n", okay ? "Yes" : "No", okay ? buy.length() - target.length() : missing);
	return 0;
}
