#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	int i, j, n1, n2, n;
	getline(cin, s);
	n = s.length();
	n1 = 1;
	n2 = n + 2 - 2 * n1;
	while(n2 >= n1) {
		++n1;
		n2 = n + 2 - 2 * n1;
	}
	--n1;
	n2 = n - 2 * n1;
	for(i = 1; i <= n1; ++i) {
		printf("%c", s[i - 1]);
		if(i != n1){
			for(j = 1; j <= n2; ++j) 
				printf(" ");
		}
		else {
			for(j = i; j < i + n2; ++j) printf("%c", s[j]);
		}
		printf("%c\n", s[n - i]);
	}
	return 0;
} 
