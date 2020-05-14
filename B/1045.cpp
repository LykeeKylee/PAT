#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long maxNum = -1, minNum;
    cin >> n;
    vector<long long> mainE, a, maxA;
    for(int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        a.emplace_back(x);
        maxA.emplace_back(maxNum);
        if(maxNum < x) maxNum = x;
    }
    for(int i = n - 1; i >= 0; --i) {
        if(i == n - 1) {
            if(a[i] > maxA[i]) mainE.emplace_back(a[i]);
            minNum = a[i];
        }
        else {
            if(a[i] > maxA[i] && a[i] < minNum) mainE.emplace_back(a[i]);
            if(minNum > a[i]) minNum = a[i];
        }
    }

    if(!mainE.empty()) {
        cout << mainE.size() << endl;
        for(int i = mainE.size() - 1; i >= 0; --i)
            printf("%s%lld", (i == mainE.size() - 1 ? "" : " "), mainE[i]);
    }
    else {
        //todo: 格式错误??????
        cout << 0 << endl << endl;
    }
    return 0;
}