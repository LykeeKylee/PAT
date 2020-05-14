#include <bits/stdc++.h>
using namespace std;

void flagcnt(string &a, int cnt[]) {
    for(auto i = a.begin(); i != a.end(); ++i)
        ++cnt[*i - '0'];
}

string double_it(string &a) {
    string b;
    int flag = 0;
    for(auto i = a.rbegin(); i != a.rend(); ++i) {
        int num = (*i - '0') * 2 + flag;
        b = char(num % 10 + '0') + b;
        flag = num / 10;
    }
    if(flag > 0) b = char(flag + '0') + b;
    return b;
}

int main() {
    int cnt1[10] = {0}, cnt2[10] = {0}, ret = 1;
    string a, b;
    getline(cin, a);
    flagcnt(a, cnt1);
    b = double_it(a);
    flagcnt(b, cnt2);
    for(int i = 0; i < 10; ++i) {
        if(cnt1[i] != cnt2[i]) {
            ret = 0;
            break;
        }
    }
    cout << (ret == 1 ? "Yes" : "No") << endl << b << endl;
}