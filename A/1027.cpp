#include<bits/stdc++.h>
using namespace std;
string convert(int x) {
	string value;
	while(x != 0) {
		int remain = x % 13;
		if(remain < 10) value = char('0' + remain) + value;
		else value = char('A' + remain - 10) + value;
		x /= 13;
	}
	while(value.length() < 2) value = '0' + value;
	return value;
}
int main() {
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf("#%s%s%s", convert(r).c_str(), convert(g).c_str(), convert(b).c_str());
	return 0;
} 
