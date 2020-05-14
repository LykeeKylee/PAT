#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
	if(x == 0 || x == 1) return false;
	else if(x == 2) return true;
	else if(x % 2 == 0) return false;
	int upper = int(sqrt(x));
	for(int i = 3; i <= upper; i += 2) {
		if(x % i == 0) return false;
	}
	return true;
}
int main() {
	int msize, n, m, i, j, x, key, sign, flag, search = 0;
	scanf("%d %d %d", &msize, &n, &m);
	while(!isprime(msize)) ++msize;
	vector<int> Hash(msize);
	for(i = 0; i < n; ++i) {
		scanf("%d", &x);
		flag = false;
//		cout << x << ": ";
        for(j = 0; j <= msize - 1; ++j) {
            key = (x % msize + j * j) % msize;
//            cout << key << ' ';
            if(Hash[key] == 0) {
                Hash[key] = x;
                flag = true;
                break;
            }
        }
//        cout << endl;
		if(!flag) printf("%d cannot be inserted.\n", x);
	}
	for(i = 0; i < m; ++i) {
		scanf("%d", &x);
        for(j = 0; j <= msize; ++j) {
            search++;
            key = (x % msize + j * j) % msize;
            if(Hash[key] == 0 || Hash[key] == x) break;
        }
	}
	printf("%0.1lf", search * 1.0 / m);
	return 0;
}
