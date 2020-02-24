#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long gcd(long long x, long long y) {
    if(x < y)
        swap(x, y);
    return y == 0 ? x : gcd(y, x % y);
}

string simp(long long a, long long b) {
    if(b == 0) return "Inf";
    else if(a == 0) return "0";
    else {
//        todo:a * b < 0 可能超出整形的范围
        long long flag = ((a > 0 && b > 0) || (a < 0 && b < 0)) ? 1 : -1, i;
        a = abs(a), b = abs(b);
        i = gcd(a, b);
        a /= i, b /= i;
        long long z = a / b, f = a % b;
        string zs, fs;
        if(z != 0 && f != 0)
            zs = to_string(z) + " ", fs = to_string(f) + '/' + to_string(b);
        else if(z != 0)
            zs = to_string(z), fs = "";
        else if(f != 0)
            zs = "", fs = to_string(f) + '/' + to_string(b);
        if(flag == -1)
            return "(-" + zs + fs + ")";
        else
            return zs + fs;
    }
}

int main() {
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    string x1 = simp(a1, b1), x2 = simp(a2, b2);
    printf("%s + %s = %s\n", x1.c_str(), x2.c_str(), simp(a1 * b2 + a2 * b1, b1 * b2).c_str());
    printf("%s - %s = %s\n", x1.c_str(), x2.c_str(), simp(a1 * b2 - a2 * b1, b1 * b2).c_str());
    printf("%s * %s = %s\n", x1.c_str(), x2.c_str(), simp(a1 * a2, b1 * b2).c_str());
    printf("%s / %s = %s\n", x1.c_str(), x2.c_str(), simp(a1 * b2, a2 * b1).c_str());
    return 0;
}