#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int cnt[128], len = str.length();
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < len; ++i) {
        ++cnt[tolower(str[i])];
    }
    int max = 0, pos = int('z') + 1;
    for(int i = int('a'); i < int('z'); ++i) {
        if(cnt[i] > max) {
            max = cnt[i];
            pos = i;
        }
        else if(cnt[i] == max && i < pos) {
            pos = i;
        }
    }
    cout << char(pos) << ' ' << max;
    return 0;
}