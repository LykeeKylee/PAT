#include<bits/stdc++.h>
using namespace std;
int n;
int sortg(int a) {
	string s = to_string(a);
	s.insert(s.begin(), 4 - s.length(), '0');
	sort(s.begin(), s.end(), greater<char>());
	return atoi(s.c_str());
}
int sortl(int a) {
	string s = to_string(a);
	s.insert(s.begin(), 4 - s.length(), '0');
	sort(s.begin(), s.end(), less<char>());
	return atoi(s.c_str());
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	scanf("%d", &n);
	int a, b, c = n;
	do {
		a = sortg(c);
		b = sortl(c);
		c = a - b;
		printf("%04d - %04d = %04d\n", a, b, c);
	} while(c != 0 && c != 6174);
	return 0;
}
