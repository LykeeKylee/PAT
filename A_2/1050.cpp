#include<bits/stdc++.h>
using namespace std;
string s1, s2;
bool c[256];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s2.length(); ++i) 
		c[int(s2[i])] = true;
	for(int i = 0; i < s1.length(); ++i)
		if(!c[int(s1[i])])
			printf("%c", s1[i]);
	return 0;
}
