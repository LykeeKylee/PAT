#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a[4];
    for(int i = 0; i < 4; ++i) {
        cin >> a[i];
    }
    double R = a[0] * a[2], P = a[1] + a[3];
    double A = R * cos(P), B = R * sin(P);
    //TODO：不四舍五入
    if(abs(A) < 0.01)
        A = 0.0;
    if(abs(B) < 0.01)
        B = 0.0;
    printf("%.2lf%c%.2lfi", A, B < 0.0 ? '-' : '+', abs(B));
    return 0;
}