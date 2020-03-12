#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, e, cnt = 0;
    double c;
    map<int, double> p1, ret;

    cin >> k;
    for(int i = 0; i < k; ++i) {
        cin >> e >> c;
        p1[e] = c;
    }
    cin >> k;
    for(int i = 0; i < k; ++i) {
        cin >> e >> c;
        for(auto j = p1.begin(); j != p1.end(); ++j) {
            ret[e + j->first] += (c * j->second);
        }
    }

    //remember to skip those items of which the coefficient is zero
    for(auto i = ret.rbegin(); i != ret.rend(); ++i){
        if(abs(i->second - 0.0) > 1e-4) {
            cnt++;
        }
    }
    cout << cnt;
    for(auto i = ret.rbegin(); i != ret.rend(); ++i){
        if(abs(i->second - 0.0) > 1e-4)
            printf("%c%d%c%0.1lf", ' ', i->first, ' ', i->second);
    }
    return 0;
}