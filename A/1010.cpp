#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll convert(string &a, ll radix) {
    ll x = 0, coef;
    coef = 0;
    for(auto c = a.rbegin(); c != a.rend(); ++c) {
        x += ((*c <= '9' ? *c - '0' : *c - 'a' + 10) * pow(radix, coef));
        coef++;
    }
    return x;
}

int main() {
    string a, b;
    ll tag, radix, x = 0, y = -1;
    cin >> a >> b >> tag >> radix;
    if(tag == 2) swap(a, b);
    x = convert(a, radix);

    char maxChar = *max_element(b.begin(), b.end());
    //use isdigit(x) to judge whether x is digital or not.
    ll low = (maxChar <= '9' ? maxChar - '0' : maxChar - 'a' + 10) + 1;
    // note that num may be out of the range of int and long long. Avoid to use unsigned types.
    ll high = max(low, x);
    while(low <= high) {
        ll mid = (low + high) / 2, tmp = convert(b, mid);
        if(tmp == x) {
            y = tmp;
            radix = mid;
            break;
        }
        else if(tmp > x || tmp < 0) high = mid - 1;
        else low = mid + 1;
    }
    if(y == -1) cout << "Impossible";
    else cout << radix;
    return 0;
}