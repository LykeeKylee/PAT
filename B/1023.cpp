#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int numCnt[10];
    memset(numCnt, 0, sizeof(numCnt));
    int size = 10, flag = -1;
    while(size--) {
        cin >> numCnt[9 - size];
        if(flag == -1 && size != 9 && numCnt[9 - size] != 0)
            flag = 9 - size;
    }
    --numCnt[flag];
    cout << flag;
    size = 10;
    int nsize;
    while(size--) {
        nsize = numCnt[9 - size];
        while(nsize--)
            cout << 9 - size;
    }
    return 0;
}