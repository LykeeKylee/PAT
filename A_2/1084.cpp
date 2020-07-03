#include<bits/stdc++.h>
using namespace std;
string origin, str;
bool exist[256], visit[256];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j;
	getline(cin, origin);
	getline(cin, str);
	transform(origin.begin(), origin.end(), origin.begin(), ::toupper);
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	for(i = 0; i < str.length(); ++i) exist[int(str[i])] = true;
	for(i = 0; i < origin.length(); ++i) {
		if(!exist[int(origin[i])] && !visit[int(origin[i])]) {
			printf("%c", origin[i]);
			visit[int(origin[i])] = true;
		}
	}
	return 0;
}
