#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool condition(const char *seq, const int *cnt) {
    return cnt[seq[0]] != 0 || cnt[seq[1]] != 0 || cnt[seq[2]] != 0 || cnt[seq[3]] != 0 || cnt[seq[4]] != 0 || cnt[seq[5]] != 0;
}

int main() {
    string str;
    getline(cin, str);
    int cnt[128], len = str.length();
    char seq[6] = {'P', 'A', 'T', 'e', 's', 't'};
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < len; ++i) {
        ++cnt[str[i]];
    }
    while(condition(seq, cnt)) {
        for(int i = 0; i < 6; ++i) {
            if(cnt[seq[i]]) {
                cout << seq[i];
                --cnt[seq[i]];
            }
        }
    }
    return 0;
}