#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x) {
    if(x == 2) return true;
    if(x <= 1 || x % 2 == 0) return false;
    else {
        for(int i = 3; i <= int(sqrt(x)); i+=2) {
            if(x % i == 0) return false;
        }
    }
    return true;
}

long long convert(long long a, long long radix) {
    string x;
    if(a == 0) return 0;
    else {
        while(a != 0) {
            x += char('0' + a % radix);
            a /= radix;
        }
    }
    long long ret = 0, flag = 1;
    for(auto i = x.rbegin(); i != x.rend(); ++i) {
        ret += ((*i - '0') * flag);
        flag *= radix;
    }
    return ret;
}

int main() {
    long long n, d;
    while(cin >> n) {
        if(n < 0) break;
        cin >> d;
        if(isPrime(convert(n, d)) && isPrime(n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}