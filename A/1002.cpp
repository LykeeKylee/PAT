#include <bits/stdc++.h>
using namespace std;

int main() {
    double an;
    map<int, double> coe;
    int k, n, cnt = 0;
    for(int j = 0; j < 2; ++j) {
        cin >> k;
        for(int i = 0; i < k; ++i) {
            cin >> n >> an;
            if(coe.find(n) == coe.end())
                coe[n] = an;
            else
                coe[n] += an;
        }
    }
    for(auto i = coe.rbegin(); i != coe.rend(); ++i) {
        if(i->second != 0.0) cnt++;
    }
    cout << cnt;
    for(auto i = coe.rbegin(); i != coe.rend(); ++i) {
        if(i->second != 0.0) printf(" %d %0.1lf", i->first, i->second);
    }
    return 0;
}