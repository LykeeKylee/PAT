#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if(a < b) swap(a, b);
	return !b ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
int main() {
	int a = 49, b = 105;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
	return 0; 
}
