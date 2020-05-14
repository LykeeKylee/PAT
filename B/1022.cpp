#include <iostream>
#include <string>
#include <algorithm>
typedef unsigned int uint;
using namespace std;

int main() {
    uint A, B, C, D;
    cin >> A >> B >> D;
    string ret;
    C = A + B;
    if(C < D)
        ret = (char('0' + C));
    else {
        while(C >= D) {
            ret += (char('0' + C % D));
            C /= D;
        }
        ret += (char('0' + C % D));
        reverse(ret.begin(), ret.end());
    }
    cout << ret;
}