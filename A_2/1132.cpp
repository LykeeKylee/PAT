#include<bits/stdc++.h>
using namespace std;
int n;
bool judge(int z) {
	int len = to_string(z).length(), a, b;
	a = z / int(pow(10, len / 2));
	b = z % int(pow(10, len / 2));
	return a != 0 && b != 0 && !(z % (a * b));
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int i, j, z;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &z); 
		printf("%s\n", judge(z) ? "Yes" : "No");
	}
	return 0;
}
