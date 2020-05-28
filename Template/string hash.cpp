#include<bits/stdc++.h>
using namespace std;
// ABC 
int hash1(string &s) {
	int id = 0;
	for(int i = 0; i < s.length(); ++i) 
		id = id * 26 + s[i] - 'A';
	return id;
}
// Abc
int hash2(string &s) {
	int id = 0;
	for(int i = 0; i < s.length(); ++i) {
		if(s[i] <= 'Z' && s[i] >= 'A') 
			id = id * 52 + s[i] - 'A';
		else
			id = id * 52 + s[i] - 'a' + 26;
	}
	return id;
} 
