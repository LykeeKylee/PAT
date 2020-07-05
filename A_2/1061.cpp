#include<bits/stdc++.h>
using namespace std;
string str1, str2, str3, str4;
string weekday[7] = {
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN"
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif
	int i, j;
	char c1, c2;
	getline(cin, str1);
	getline(cin, str2);
	getline(cin, str3);
	getline(cin, str4);
	int len = str1.length() < str2.length() ? str1.length() : str2.length();
	i = j = 0;
	while(i < len && j < 2) {
		if(str1[i] == str2[i]) {
			if(j == 0 && str1[i] <= 'G' && str1[i] >= 'A') {
				++j;
				c1 = str1[i];
			} else if(j == 1 && (isdigit(str1[i]) || (str1[i] <= 'N' && str1[i] >= 'A'))) {
				++j;
				c2 = str1[i];
			}
		}
		++i;
	}
	len = str3.length() < str4.length() ? str3.length() : str4.length();
	i = 0;
	while(str3[i] != str4[i] || !isalpha(str3[i])) ++i;
	printf("%s %02d:%02d\n", weekday[c1 - 'A'].c_str(), isdigit(c2) ? c2 - '0': c2 - 'A' + 10, i);
	return 0;
}
