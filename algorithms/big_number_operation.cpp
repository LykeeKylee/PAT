#include <iostream>
#include <string>
using namespace std;

// a + b
string add(string a, string b) {
    if(a.length() == 0 || b.length() == 0) return "E";
    int flag = 0, x;
    string ret;
    if(a.length() < b.length()) swap(a, b);
    for(auto i = a.rbegin(), j = b.rbegin(); i != a.rend(); ++i) {
        if(j != b.rend()) {
            x = *i + *j - 2 * '0' + flag;
            ++j;
        }
        else x = *i - '0' + flag;
        ret  = char(x % 10 + '0') + ret;
        flag = x / 10;
    }
    if(flag != 0) ret = '1' + ret;
    auto r = ret.begin();
    for(; *r == '0'; ++r);
    if(r != ret.end()) ret = ret.substr(r - ret.begin(), ret.end() - r);
    else ret = "0";
    return ret;
}

// a - b
string minus_(string a, string b) {
    if(a.length() == 0 || b.length() == 0) return "E";
    bool sign = false;
    if(a.length() < b.length() || (a.length() == b.length() && a < b)) {
        swap(a, b);
        sign = true;
    }
    string ret;
    int flag = 0, x;
    for(auto i = a.rbegin(), j = b.rbegin(); i != a.rend(); ++i) {
        if(j != b.rend()) {
            x = *i - *j - flag;
            ++j;
        }
        else x = *i - '0' - flag;
        if(x < 0) {
            flag = 1;
            x += 10;
        }
        ret = char(x + '0') + ret;
    }
    auto r = ret.begin();
    for(; *r == '0'; ++r);
    if(r != ret.end()) ret = ret.substr(r - ret.begin(), ret.end() - r);
    else ret = "0";
    if(sign) ret = '-' + ret;
    return ret;
}

string mul(string a, string b) {
    if(a.length() == 0 || b.length() == 0) return "E";
    if(a == "0" || b == "0") return "0";
    bool sign = false;
    if(a[0] == '-') {
        a = a.substr(1, a.length() - 1);
        sign = !sign;
    }
    if(b[0] == '-') {
        b = b.substr(1, b.length() - 1);
        sign = !sign;
    }
    if(a.length() < b.length()) swap(a, b);
    string ret = "0";
    int flag = 0, x, zero = 0;
    for(auto i = b.rbegin(); i != b.rend(); ++i) {
        string tmp;
        flag = 0;
        for(auto j = a.rbegin(); j != a.rend(); ++j) {
            x = (*i - '0') * (*j - '0') + flag;
            tmp = char(x % 10 + '0') + tmp;
            flag = x / 10;
        }
        if(flag != 0) tmp = char('0' + flag) + tmp;
        for(int z = 0; z < zero; ++z) tmp += '0';
        zero++;
        ret = add(tmp, ret);
    }
    auto r = ret.begin();
    for(; *r == '0'; ++r);
    if(r != ret.end()) ret = ret.substr(r - ret.begin(), ret.end() - r);
    else ret = "0";
    if(sign) ret = '-' + ret;
    return ret;
}

int main() {
    cout << "999 + 1 = " << add("999", "1") << endl;
    cout << "500 + 0 = " << add("500", "0") << endl;
    cout << "58999 + 10 = " << add("58999", "10") << endl << endl;

    cout << "99 - 999 = " << minus_("99", "999") << endl;
    cout << "99 - 100 = " << minus_("99", "100") << endl;
    cout << "100 - 100 = " << minus_("100", "100") << endl << endl;

    cout << "1234 * 11 = " << mul("1234", "11") << endl;
    cout << "-99999 * 99999 = " << mul("-99999", "99999") << endl;
    cout << "100000 * 001 = " << mul("100000", "001") << endl;
}

