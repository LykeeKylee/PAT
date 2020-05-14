#include <iostream>
#include <string>
using namespace std;

// a + b
string add(string a, string b) {
//    if(a.length() == 0 || b.length() == 0) return "E";
//    int flag = 0, x;
//    string ret;
//    if(a.length() < b.length()) swap(a, b);
//    for(auto i = a.rbegin(), j = b.rbegin(); i != a.rend(); ++i) {
//        if(j != b.rend()) {
//            x = *i + *j - 2 * '0' + flag;
//            ++j;
//        }
//        else x = *i - '0' + flag;
//        ret  = char(x % 10 + '0') + ret;
//        flag = x / 10;
//    }
//    if(flag != 0) ret = '1' + ret;
//    auto r = ret.begin();
//    for(; *r == '0'; ++r);
//    if(r != ret.end()) ret = ret.substr(r - ret.begin(), ret.end() - r);
//    else ret = "0";
//    return ret;
    int len = a.length() > b.length() ? a.length() : b.length(), flag = 0, x;
    a.insert(a.begin(), len - a.length(), '0');
    b.insert(b.begin(), len - b.length(), '0');
    string ret;
    for(auto i = a.rbegin(), j = b.rbegin(); i != a.rend(); ++i, ++j) {
        x = *i + *j - 2 * '0' + flag;
        ret = char(x % 10 + '0') + ret;
        flag = x / 10;
    }
    if(flag != 0) ret = char(flag + '0') + ret;
    return ret;
}

// a - b
string minus_(string a, string b) {
//    if(a.length() == 0 || b.length() == 0) return "E";
//    bool sign = false;
//    if(a.length() < b.length() || (a.length() == b.length() && a < b)) {
//        swap(a, b);
//        sign = true;
//    }
//    string ret;
//    int flag = 0, x;
//    for(auto i = a.rbegin(), j = b.rbegin(); i != a.rend(); ++i) {
//        if(j != b.rend()) {
//            x = *i - *j - flag;
//            ++j;
//        }
//        else x = *i - '0' - flag;
//        if(x < 0) {
//            flag = 1;
//            x += 10;
//        }
//        ret = char(x + '0') + ret;
//    }
//    auto r = ret.begin();
//    for(; *r == '0'; ++r);
//    if(r != ret.end()) ret = ret.substr(r - ret.begin(), ret.end() - r);
//    else ret = "0";
//    if(sign) ret = '-' + ret;
//    return ret;
    int len = a.length() > b.length() ? a.length() : b.length(), flag = 0, x;
    a.insert(a.begin(), len - a.length(), '0');
    b.insert(b.begin(), len - b.length(), '0');
    string ret, sign;
    if(a < b) {
        swap(a, b);
        sign = "-";
    }
    for(auto i = a.rbegin(), j = b.rbegin(); i != a.rend(); ++i, ++j) {
        x = *i - *j + flag;
        flag = x < 0 ? -1 : 0;
        x = x < 0 ? x + 10 : x;
        ret = char(x % 10 + '0') + ret;
    }
    ret = sign + ret;
    return ret;
}

string mul(string a, string b) {
//    if(a.length() == 0 || b.length() == 0) return "E";
//    if(a == "0" || b == "0") return "0";
//    bool sign = false;
//    if(a[0] == '-') {
//        a = a.substr(1, a.length() - 1);
//        sign = !sign;
//    }
//    if(b[0] == '-') {
//        b = b.substr(1, b.length() - 1);
//        sign = !sign;
//    }
//    if(a.length() < b.length()) swap(a, b);
//    string ret = "0";
//    int flag = 0, x, zero = 0;
//    for(auto i = b.rbegin(); i != b.rend(); ++i) {
//        string tmp;
//        flag = 0;
//        for(auto j = a.rbegin(); j != a.rend(); ++j) {
//            x = (*i - '0') * (*j - '0') + flag;
//            tmp = char(x % 10 + '0') + tmp;
//            flag = x / 10;
//        }
//        if(flag != 0) tmp = char('0' + flag) + tmp;
//        for(int z = 0; z < zero; ++z) tmp += '0';
//        zero++;
//        ret = add(tmp, ret);
//    }
//    auto r = ret.begin();
//    for(; *r == '0'; ++r);
//    if(r != ret.end()) ret = ret.substr(r - ret.begin(), ret.end() - r);
//    else ret = "0";
//    if(sign) ret = '-' + ret;
//    return ret;
    if(a.length() < b.length()) swap(a, b);
    int flag = 0, x;
    string ret;
    for(auto j = b.rbegin(); j != b.rend(); ++j) {
        string tmp;
        for(auto i = a.rbegin(); i != a.rend(); ++i) {
            x = (*j - '0') * (*i - '0') + flag;
            tmp = char(x % 10 + '0') + tmp;
            flag = x / 10;
        }
        if(flag != 0) tmp = char(flag + '0') + tmp;
        tmp.insert(tmp.end(), j - b.rbegin(), '0');
        ret = add(ret, tmp);
    }
    return ret;
}

int main() {
    cout << "999 + 1 = " << add("999", "1") << endl;
    cout << "500 + 0 = " << add("500", "0") << endl;
    cout << "58999 + 10 = " << add("58999", "10") << endl << endl;

    cout << "99 - 999 = " << minus_("99", "999") << endl;
    cout << "99 - 100 = " << minus_("99", "100") << endl;
    cout << "100 -  2 = " << minus_("100", "2") << endl << endl;

    cout << "11 * 11 = " << mul("11", "11") << endl;
    cout << "100000 * 99 = " << mul("100000", "99") << endl;
}

