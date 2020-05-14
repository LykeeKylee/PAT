#include <bits/stdc++.h>
using namespace std;
map<int, string> ranklist;
bool isprime(int x) {
	if(x == 0 || x == 1) return false;
	else if(x == 2) return  true;
	else if(x % 2 == 0)  return false;
	int upper = int(sqrt(x));
	for(int i = 3; i <= upper; i += 2) {
		if(x % i == 0) return false;
	}
	return true;
}
int main() {
	int n, k, i, j, id;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) {
		scanf("%d", &id);
		if(i == 1) ranklist[id] = "Mystery Award";
		else if(isprime(i)) ranklist[id] = "Minion";
		else ranklist[id] = "Chocolate";
	}
	scanf("%d", &k);
	for(i = 1; i <= k; ++i) {
		scanf("%d", &id);
		if(ranklist[id].empty()) printf("%04d: Are you kidding?\n", id);
		else {
			printf("%04d: %s\n", id, ranklist[id].c_str());
			ranklist[id] = "Checked";
		}
	}
	return 0;
}
 
