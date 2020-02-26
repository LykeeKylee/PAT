#include <bits/stdc++.h>
using namespace std;

void select(int size, int &m, int &n) {
    int gap = size;
    for(int i = 1; i <= sqrt(size); ++i) {
        if(size % i == 0 && gap > (size / i - i)) {
            m = gap / i;
            n = i;
        }
    }
}

bool cmp(int &x, int &y) {
    return x > y;
}

int main() {
    int size, m, n, *s, _m, _n;
    cin >> size;
    select(size, m, n);
    _m = m, _n = n;
    s = new int[size + 1];
    for(int i = 0; i < size; ++i) cin >> s[i];
    sort(s, s + size, cmp);
    vector<vector<int>> l(m, vector<int>(n));
    bool f1 = true, f2 = true;
    int mm = 0, nn = 0, i = 0, j;
    while(i < size) {
        if(f1 && f2) {
            for(j = 0; j < n; ++j)
                l[mm][nn + j] = s[i++];
            --m;
            ++mm;
            nn = nn + j - 1;
            f2 = false;
        }
        else if(f1 && !f2) {
            for(j = 0; j < m; ++j)
                l[mm + j][nn] = s[i++];
            --n;
            --nn;
            mm = mm + j - 1;
            f1 = false;
        }
        else if(!f1 && !f2) {
            for(j = 0; j < n; ++j)
                l[mm][nn - j] = s[i++];
            --m;
            --mm;
            nn = nn - j + 1;
            f2 = true;
        }
        else if(!f1 && f2) {
            for(j = 0; j < m; ++j)
                l[mm - j][nn] = s[i++];
            --n;
            ++nn;
            mm = mm - j + 1;
            f1 = true;
        }
    }
    for(i = 0; i < _m; ++i) {
        for(j = 0; j < _n; ++j) {
            if(j != 0)
                cout << ' ';
            cout << l[i][j];
        }
        cout << endl;
    }
    return 0;
}