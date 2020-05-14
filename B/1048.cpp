#include <iostream>
#include <string>
using namespace std;

int main() {
    string x, y, s;
    cin >> x >> y;
    int xlen = x.length(), ylen = y.length(), t;
    //todo: ¶ñÐÄ
    if(ylen < xlen)
        y.insert(0, xlen - ylen, '0');
    ylen = y.length();
    for(int i = ylen - 1, j = xlen - 1; i >= 0; --i, --j) {
        if(j >= 0) {
            if((ylen - i) % 2 == 0) {
                t = y[i] - x[j];
                if(t < 0)
                    t += 10;
                s = char('0' + t) + s;
            }
            else {
                t = y[i] + x[j] - 2 * int('0');
                t %= 13;
                if(t == 10)
                    s = 'J' + s;
                else if(t == 11)
                    s = 'Q' + s;
                else if(t == 12)
                    s = 'K' + s;
                else if(t < 10)
                    s = char('0' + t) + s;
            }
        }
        else
            s = y[i] + s;
    }
    cout << s;
    return 0;
}