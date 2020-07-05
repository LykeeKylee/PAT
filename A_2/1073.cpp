#include<bits/stdc++.h>
using namespace std;
string a;
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif
	getline(cin, a);
	int flag = a[0] == '-' ? -1 : 1, e = find(a.begin(), a.end(), 'E') - a.begin();
	string number = a.substr(1, e - 1), exponent = a.substr(e + 1, a.length() - e - 1);
	int ex = atoi(exponent.c_str()), eflag;
	eflag = ex < 0 ? -1 : 1;
	ex = abs(ex);
	string ans = number;
	if(ex != 0) {
		if(eflag == 1) {
			int dot = find(number.begin(), number.end(), '.') - number.begin();
			if(ex >= number.length() - 1 - dot) {
				ans.erase(1, 1);
				ans.insert(ans.end(), ex - (number.length() - 1 - dot), '0');
			} else {
				ans.insert(dot + ex + 1, 1, '.');
				ans.erase(1, 1);
			}
		} else {
			ans.erase(1, 1);
			ans.insert(ans.begin(), ex - 1, '0');
			ans = "0." + ans;
		}
	}
	printf("%s%s", flag == -1 ? "-": "", ans.c_str());
	return 0;
}
