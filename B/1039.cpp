#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string sell, want;
    getline(cin, sell);
    getline(cin, want);
    int lenSell = sell.length(), lenWant = want.length(), cntSell[128], cntWant[128], sum = 0;
    memset(cntSell, 128, sizeof(cntSell));
    memset(cntWant, 128, sizeof(cntWant));
    for(int i = 0; i < lenWant; ++i) {
        ++cntWant[int(want[i])];
    }
    for(int i = 0; i < lenSell; ++i) {
        if(cntSell[int(sell[i])] < cntWant[int(sell[i])]) {
            ++cntSell[int(sell[i])];
            ++sum;
        }
    }
    if(sum == lenWant)
        cout << "Yes " << lenSell - sum;
    else
        cout << "No " << lenWant - sum;

    return 0;
}