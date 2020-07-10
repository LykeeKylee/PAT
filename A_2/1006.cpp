#include<bits/stdc++.h>
using namespace std;
struct signtime {
	string id;
	int t;
};
int n;
vector<signtime> signlist;
bool cmp(signtime &a, signtime &b) {
	return a.t < b.t;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		string id;
		int hh, mm, ss, t;
		cin >> id;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		t = hh * 60 * 60 + mm * 60 + ss;
		signtime tmp{id, t};
		signlist.push_back(tmp);
		scanf("%d:%d:%d", &hh, &mm, &ss);
		t = hh * 60 * 60 + mm * 60 + ss;
		tmp = {id, t};
		signlist.push_back(tmp);
	}
	sort(signlist.begin(), signlist.end(), cmp);
	printf("%s %s", signlist.front().id.c_str(), signlist.back().id.c_str());
	return 0;
	
}
