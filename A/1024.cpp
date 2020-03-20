#include <bits/stdc++.h>
using namespace std;

string add(string &a, string &b) {
    string ret;
    int flag = 0;
    auto i = a.rbegin(), j = b.rbegin();
    for(; i != a.rend() && j != b.rend(); ++i, ++j) {
        int x = (*i - '0') + (*j - '0') + flag;
        ret = char(x % 10 + '0') + ret;
        flag = x / 10;
    }
    if(flag != 0) ret = '1' + ret;
    return ret;
}

int main() {
    long long n, k;
    int i = 0, find_ = 0;
    cin >> n >> k;
    string a = to_string(n);
    for(i = 0; i < k; ++i) {
        string ra = a;
        reverse(ra.begin(), ra.end());
        if(ra == a) {
            cout << a << endl << i;
            find_ = 1;
            break;
        }
        else {
            a = add(a, ra);
        }
    }
    if(find_ != 1 && k != 0) {
        cout << a << endl << k;
    }
    return 0;
}