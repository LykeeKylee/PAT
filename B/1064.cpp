#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int N, i, friendNum[9 * 5 + 1] = {0};
    cin >> N;
    i = N;
    string x;
    while(i--) {
        cin >> x;
        int cnt = 0;
        for(char j: x) {
            cnt += (j - '0');
        }
        ++friendNum[cnt];
    }
    int cnt = 0, flag = 0;
    string fstr;
    for(int j = 0; j < 46; ++j) {
        if(friendNum[j] > 0) {
            ++cnt;
            fstr += (flag > 0 ? " " : "") + to_string(j);
            ++flag;
        }
    }
    cout << cnt << endl << fstr;
    return 0;
}