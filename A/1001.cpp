#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, len, c, cnt = 0;
    string ret, flag;
    cin >> a >> b;
    c = a + b;
    flag = c < 0 ? "-" : "";
    c = abs(c);
    ret = to_string(c);
    len = ret.length();
    cout << flag;
    for(int i = len - 1; i >= 0; --i) {
        ++cnt;
        if(cnt % 3 == 0 && i != 0) {
            ret.insert(i, 1, ',');
            cnt = 0;
        }
    }
    cout << ret;
    return 0;
}