#include <iostream>
using namespace std;

int main() {
    int price[3], pay[3], psum, paysum, ret;
    scanf("%d.%d.%d", price, price + 1, price + 2);
    scanf("%d.%d.%d", pay, pay + 1, pay + 2);

    psum = price[0] * 29 * 17 + price[1] * 29 + price[2];
    paysum = pay[0] * 29 * 17 + pay[1] * 29 + pay[2];
    ret = paysum - psum;
    if(ret < 0)
        cout << '-';
    ret = abs(ret);
    cout << ret / (29 * 17) << '.' << ret % (29 * 17) / 29 << '.' << ret % (29 * 17) % 29;
    return 0;
}