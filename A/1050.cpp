#include<bits/stdc++.h>
using namespace std;
int main() {
	string s1, s2;
	bool exist[256];
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s2.length(); ++i) exist[int(s2[i])] = true;
	for(int i = 0; i < s1.length(); ++i)
		if(!exist[int(s1[i])]) 
			printf("%c", s1[i]);
	return 0;
} 
