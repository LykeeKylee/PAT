#include <string>
#include <iostream>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    unsigned long long cntP = 0, cntT = 0, cntA = 0, len = str.length();
    for(int i = len - 1; i >= 0; --i) {
        if(str[i] == 'P')      cntP += cntA;
        else if(str[i] == 'A') cntA += cntT;
        else ++cntT;
    }
    printf("%llu", (cntP % 1000000007));
    return 0;
}