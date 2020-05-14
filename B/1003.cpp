#include <iostream>
#include <string>
using namespace std;

bool check(string &str) {
    int p, t, cntp = 0, cntt = 0;
    string a, b, c;
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T')
            return false;
        else if (str[i] == 'P')
            p = i, cntp++;
        else if(str[i] == 'T')
            t = i, cntt++;
    }
    if(cntp != 1 || cntt != 1)
        return false;
    else if(p > t || t == p + 1)
        return false;
    else {
        a = str.substr(0, p);
        b = str.substr(p + 1, t - p - 1);
        c = str.substr(t + 1, str.length() - t - 1);
    }
    return a.length() * b.length() == c.length();
}

int main() {
    int n = 0;
    cin >> n;
    string x;
    while(n--) {
        cin >> x;
        if(check(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}