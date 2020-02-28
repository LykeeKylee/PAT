#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    double *s = new double[n], len = 0;
    for(int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n);
    for(int i = 0; i < n; ++i) {
        if(i == 0) len = s[i];
        else len = (len / 2 + s[i] / 2);
//        cout << len << endl;
    }
    cout << floor(len) << endl;
    return 0;
}