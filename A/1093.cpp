#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	int end, i, len = str.length();
	long long t = 0, at = 0, pat = 0;
	for(i = 0; i < len; ++i) {
		if(str[i] == 'P') {
			end = i;
			break;
		}
	}
	for(i = len - 1; i >= end; --i) {
		if(str[i] == 'T') ++t;
		else if(str[i] == 'A') at += t;
		else pat += at;
	}
	printf("%d\n", pat % 1000000007);
	return 0;
} 
