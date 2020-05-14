#include <iostream>
using namespace std;

//todo:注意数据类型的问题
string learn(double m, double n) {
    return m != n ? (m > n ? "Gai" : "Cong") : "Ping";
}

int main() {
    int M, x, y, xpy, xmy, jia = -1, yi;
    double bing;
    cin >> M >> x >> y;
    for(int i = 99; i >= 10; --i) {
        jia = i;
        yi = jia % 10 * 10 + jia / 10;
        bing = yi * 1.0 / y;
        if(abs(jia - yi) * 1.0 / x == bing)
            break;
        else
            jia = -1;
    }
    if(jia == -1)
        cout << "No Solution";
    else
        cout << jia << " " + learn(M, jia) << " " + learn(M, yi) << " " + learn(M, bing);
    return 0;
}