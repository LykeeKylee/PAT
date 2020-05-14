#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return a % b == 0 ? b : gcd(a % b, b);
}

int main() {
    cout << gcd(120, 80) << endl;
    return 0;
}