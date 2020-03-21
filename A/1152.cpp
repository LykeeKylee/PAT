#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long a) {
    if(a == 0 || a == 1) return false;
    else if(a == 2) return true;
    else if(a % 2 == 0) return false;
    int upper = int(sqrt(a));
    for(int i = 3; i <= upper; i+=2) {
        if(a % i == 0) return false;
    }
    return true;
}

int main() {
    int l, k, i, findx = 0;
    cin >> l >> k;
    getchar();
    string number, prime;
    getline(cin, number);
    for(i = 0; i <= l - k; ++i) {
        prime = number.substr(i, k);
        long long x = 0, flag = 1;
        for(auto j = prime.rbegin(); j != prime.rend(); ++j) {
            x += (flag * int(*j - '0'));
            flag *= 10;
        }
        if(is_prime(x)) {
            findx = 1;
            break;
        }
    }
    if(findx == 1) cout << prime;
    else cout << 404;
    return 0;
}