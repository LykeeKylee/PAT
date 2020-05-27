#include<bits/stdc++.h>
using namespace std;
const int msize = 1e6 + 1;
int prime[msize], cnt = 0;
bool isprime[msize];
void find_prime(int n) {
	prime[0] = prime[1] = false;
	fill(isprime, isprime + msize, true);
	for(int i = 2; i < n; ++i) {
		if(isprime[i]) {
			prime[cnt++] = i;
			for(int j = i * 2; j < n; j += i) isprime[j] = false;
		}
	}
}
int main() {
	find_prime(1000);
	for(int i = 0; i < cnt; ++i) cout << prime[i] << endl;
} 
