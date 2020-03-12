#include <bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;

ull convert(string &a, ull radix) {
    ull x = 0, coef;
    coef = 0;
    for(auto c = a.rbegin(); c != a.rend(); ++c) {
        x += ((*c <= '9' ? *c - '0' : *c - 'a' + 10) * pow(radix, coef));
        coef += 1;
    }
    return x;
}

int main() {
    string a, b;
    ull tag, radix, x = 0, y = 0, coef;
    cin >> a >> b >> tag >> radix;
    if(tag == 2) swap(a, b);
    x = convert(a, radix);

    char maxChar = *max_element(b.begin(), b.end());
    int low = (maxChar <= '9' ? maxChar - '0' : maxChar - 'a' + 10) + 1;

    return 0;
}