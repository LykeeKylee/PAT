#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N, max = 0, a, b;
    cin >> N;
    while(N--) {
        cin >> a >> b;
        int x = a * a + b * b;
        if(x > max)
            max = x;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << sqrt(max * 1.0);
    return 0;
}