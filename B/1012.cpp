#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int num;
    cin >> num;
    int x;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = -1000, signal = 1, a4n = 0;
    bool flag[5];
    memset(flag, false, sizeof(flag));
    for(int i = 0; i < num; ++i) {
        cin >> x;
        if(x % 5 == 0 && x % 2 == 0){
            a1 += x;
            flag[0] = true;
        }
        else if(x % 5 == 1) {
            a2 += (signal * x);
            signal *= -1;
            flag[1] = true;
        }
        else if(x % 5 == 2){
            ++a3;
            flag[2] = true;
        }
        else if(x % 5 == 3){
            a4 += x;
            ++a4n;
            flag[3] = true;
        }
        //TODO:Attention
        else if(x % 5 == 4){
            a5 = x > a5 ? x : a5;
            flag[4] = true;
        }
    }

    if(flag[0])
        printf("%d ", a1);
    else
        cout << 'N' << ' ';
    if(flag[1])
        printf("%d ", a2);
    else
        cout << 'N' << ' ';
    if(flag[2])
        printf("%d ", a3);
    else
        cout << 'N' << ' ';
    if(flag[3])
        printf("%0.1f ", double(a4) / a4n);
    else
        cout << 'N' << ' ';
    if(flag[4])
        printf("%d", a5);
    else
        cout << 'N';
    return 0;
}