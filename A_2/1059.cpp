#include<bits/stdc++.h>
using namespace std;
struct fac {
	int p, k;
};
int msize;
vector<int> prime;
vector<bool> isprime;
vector<fac> faclist;
void get_prime() {
	isprime[0] = isprime[1] = false;
	for(int i = 2; i < msize; ++i) {
		if(isprime[i]) {
			prime.push_back(i);
			for(int j = i + i; j < msize; j += i) isprime[j] = false;
		}
	}
}
void get_fac(int n) {
	for(int i = 0; i < prime.size() && n != 0; ++i) {
		if(n % prime[i] == 0) {
			int cnt = 0;
			while(n != 1 && n % prime[i] == 0) {
				++cnt;
				n /= prime[i];
			}
			fac tmp{prime[i], cnt};
			faclist.push_back(tmp);
		}
	}
	if(n != 1) {
		fac tmp{n, 1};
		faclist.push_back(tmp); 
	}
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	msize = (int)sqrt(1.0 * n) + 1;
	isprime.resize(msize + 1);
	fill(isprime.begin(), isprime.end(), true);
	get_prime();
	if(n <= 1) printf("%d=%d", n, n);
	else {
		get_fac(n);
		printf("%d", n);
		for(int i = 0; i < faclist.size(); ++i) {
			printf("%c", i == 0 ? '=' : '*');
			printf("%d", faclist[i].p);
			if(faclist[i].k > 1) printf("^%d", faclist[i].k);
		}
	}
	return 0;
} 
