#include<bits/stdc++.h>
using namespace std;
int main() {
	string a, b, c, d, weekday[8] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	cin >> a >> b >> c >> d;
	int len = a.length() < b.length() ? a.length() : b.length(), cnt = 0;
	for(int i = 0; i < len; ++i) {
		if(a[i] == b[i]) {
			if(cnt == 0 && a[i] >= 'A' && a[i] <= 'G') {
				cout << weekday[a[i] - 'A'] << ' ';
				++cnt;
			}
			else if(cnt == 1 && (a[i] >= 'A' && a[i] <= 'N' || isdigit(a[i]))) {
				if(isdigit(a[i])) printf("%02d:", a[i] - '0');
				else printf("%02d:", 10 + a[i] - 'A');
				break;
			}
		}
	}
	len = c.length() < d.length() ? c.length() : d.length();
	for(int i = 0; i < len; ++i) {
		if(isalpha(c[i]) && c[i] == d[i]) {
			printf("%02d\n", i);
			break;
		}
	}
	return 0;
}
