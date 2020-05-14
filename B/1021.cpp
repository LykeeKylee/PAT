#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string num;
    cin >> num;
    int a[10];
    memset(a, 0, sizeof(a));
    for(int i = 0; i < num.length(); ++i) {
        int l = num[i] - '0';
        ++a[l];
    }
    bool flag = false;
    for(int i = 0; i < 10; ++i) {
        if(a[i] != 0) {
            if(!flag) {
                printf("%d:%d", i, a[i]);
                flag = true;
            }
            else {
                printf("\n%d:%d", i, a[i]);
            }
        }
    }
    return 0;
}