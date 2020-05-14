#include<bits/stdc++.h>
using namespace std;
string lines[102];
int main() {
	int n, i, j, min_len = 999999999;
	string kuchi;
	scanf("%d", &n);
	getchar();
	for(i = 0; i < n; ++i) {
		getline(cin, lines[i]);
		min_len = min_len > lines[i].length() ? lines[i].length() : min_len; 
	}
	for(i = 1; i <= min_len; ++i) {
		bool flag = true;
		int len = lines[0].length();
		char c = lines[0][len - i];
		for(j = 1; j < n; ++j) {
			len = lines[j].length();
			if(lines[j][len - i] != c) {
				flag = false;
				break;
			}
		}
		if(flag) kuchi = c + kuchi;
		else break;
	}
	if(kuchi.length() == 0) printf("nai\n");
	else printf("%s\n", kuchi.c_str());
	return 0;
} 
