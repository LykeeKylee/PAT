#include<bits/stdc++.h>
using namespace std;
bool c[256];
int main() {
	string origin, type_out;
	set<char> tmp;
	vector<char> ret;
	getline(cin, origin);
	getline(cin, type_out);
	for(int i = 0; i < type_out.length(); ++i) c[toupper(type_out[i])] = true;
	for(int i = 0; i < origin.length(); ++i) {
		if(!c[toupper(origin[i])] && tmp.find(toupper(origin[i])) == tmp.end()) {
			tmp.insert(toupper(origin[i]));
			ret.emplace_back(toupper(origin[i]));
		}
	}
	for(int i = 0; i < ret.size(); ++i) printf("%c%s", ret[i], i == ret.size() - 1 ? "\n":"");
	return 0;
}
