#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(string &str) {
    int len = str.length();
    for(int i = 0; i <= len / 2; ++i) {
        if(str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

string cal(string &a, string &b) {
    string ret;
    int jinwei = 0;
    for(int i = a.length() - 1; i >= 0; --i) {
        ret = char((a[i] - '0' + b[i] - '0' + jinwei) % 10 + '0') + ret;
        jinwei = (a[i] - '0' + b[i] - '0' + jinwei) / 10;
    }
    if(jinwei != 0) ret = '1' + ret;
    return ret;
}

int main() {
    string a;
    cin >> a;
    int i = 0;
    while(!check(a) && i < 10) {
        string b = a;
        reverse(b.begin(), b.end());
        cout << a << " + " << b << " = ";
        a = cal(a, b);
        cout << a << endl;
        ++i;
    }
    if(check(a))
        cout << a << " is a palindromic number.";
    else
        cout << "Not found in 10 iterations.";
    return 0;
}