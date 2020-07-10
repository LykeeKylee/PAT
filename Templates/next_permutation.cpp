#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[5] = {1, 2, 3, 4, 5};
	do {
		for(int i = 0; i < 5; ++i)
			printf("%d%s", a[i], i == 4 ? "\n" : " ");
	} while(next_permutation(a, a + 5));
	return 0;
} 
