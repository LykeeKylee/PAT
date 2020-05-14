#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

 vector<ll> convert(ll n, ll b) {
     vector<ll> ret;
    if(n == 0) return vector<ll>(1, 0);
    while(n != 0) {
        ret.emplace_back(n % b);
        n /= b;
    }
    return ret;
}

int main() {
    ll n, b;
    bool f = true;
    cin >> n >> b;
    vector<ll> ret = convert(n, b);
    for(int i = 0; i <= ret.size() / 2; ++i) {
        if(ret[i] != ret[ret.size() - 1 - i]) {
            f = false;
            break;
        }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(auto i = ret.rbegin(); i != ret.rend(); ++i) {
        printf("%s%lld", (i == ret.rbegin() ? "": " "), *i);
    }
    return 0;
}