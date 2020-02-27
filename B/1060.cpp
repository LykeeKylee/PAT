#include <bits/stdc++.h>
using namespace std;

bool cmp(int &a, int &b) {
    return a > b;
}

int main() {
    int n, seq[100005], elden = 0, p = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> seq[i];
    sort(seq, seq + n, cmp);
    while(elden < n && seq[p] > p + 1) {
        ++elden, ++p;
    }
    cout << elden;
    return 0;
}