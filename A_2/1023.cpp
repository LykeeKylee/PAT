#include<bits/stdc++.h>
using namespace std;
string n;
int cnt1[10], cnt2[10];
string doubleN() {
	string dn;
	int flag = 0;
	for(int i = n.length() - 1; i >= 0; --i) {
		int x = 2 * (n[i] - '0') + flag;
		dn = char('0' + x % 10) + dn;
		flag = x / 10;
	}
	if(flag != 0) dn = char('0' + flag) + dn;
	return dn;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	cin >> n;
	string dn = doubleN();
	if(n.length() != dn.length()) 
		printf("No\n%s", dn.c_str());
	else {
		for(int i = 0; i < n.length(); ++i) {
			cnt1[int(n[i] - '0')]++;
			cnt2[int(dn[i] - '0')]++;
		}
		bool flag = true;
		for(int i = 0; i < 10 && flag; ++i) {
			if(cnt1[i] != cnt2[i]) 
				flag = false;
		}
		if(flag) printf("%s\n%s", "Yes", dn.c_str());
		else printf("No\n%s", dn.c_str());
	}
	return 0;
}
