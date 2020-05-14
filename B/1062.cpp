#include <iostream>
#include <cmath>
using namespace std;

int judge(int x, int y) {
    if(x < y) swap(x, y);
    return y == 0 ? x : judge(y, x % y);
}

int main() {
    int a[2], b[2], c, low, upper;
    scanf("%d/%d %d/%d %d", a, a + 1, b, b + 1, &c);
    if(a[0] * b[1] > b[0] * a[1]) { swap(a[0], b[0]); swap(a[1], b[1]);}
    bool flag = false;

//    todo:必须取两个分数之间的数字
//    low = ceil(a[0] * c * 1.0 / a[1]), upper = floor(b[0] * c * 1.0 / b[1]);
//    for(int i = low; i <= upper; ++i) {
//        if(judge(i, c) == 1) {
//            if(flag) cout << ' ';
//            printf("%d/%d", i, c);
//            flag = true;
//        }
//    }

    for(int i = a[0] * c / a[1] + 1; i * b[1] < b[0] * c; ++i) {
        if(judge(i, c) == 1) {
            if(flag) cout << ' ';
            printf("%d/%d", i, c);
            flag = true;
        }
    }
    return 0;
}