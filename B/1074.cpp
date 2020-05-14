#include <iostream>
#include <string>
using namespace std;

int main() {
    string jinzhi, a, b, ret;
    cin >> jinzhi >> a >> b;
    int maxlen = a.length() > b.length() ? a.length() : b.length();
    a.insert(0, maxlen - a.length(), '0');
    b.insert(0, maxlen - b.length(), '0');
    int jinwei = 0;
    for(int i = maxlen - 1; i >= 0; --i) {
        ret = char((a[i] - '0' + jinwei + b[i] - '0') % (jinzhi[i] == '0' ? 10 : jinzhi[i] - '0') + '0') + ret;
        jinwei =  (a[i] - '0' + jinwei + b[i] - '0') / (jinzhi[i] == '0' ? 10 : jinzhi[i] - '0');
    }
    if(jinwei != 0) ret = '1' + ret;
    bool zero = false;
    for(char i : ret) {
        if(i != '0') zero = true;
        if(zero) cout << i;
    }
    if(!zero) cout << "0";
    return 0;
}