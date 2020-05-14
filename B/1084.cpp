#include <iostream>
#include <string>
using namespace std;

string cal(string &pre, int n, int N) {
    string ret;
    if(n < N) {
        int len = pre.length(), i, start;
        i = 0;
        while(i < len) {
            start = i;
            ++i;
            while(i < len && pre[i] == pre[start]) ++i;
            ret += (pre[start] + to_string(i - start));
        }
        return cal(ret, n + 1, N);
    }
    else
        return pre;
}

int main() {
    string d;
    int N;
    cin >> d >> N;
    string ret = cal(d, 1, N);
    cout << ret;
    return 0;
}