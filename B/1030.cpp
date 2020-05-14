#include <iostream>
#include <vector>
#include <algorithm>
typedef unsigned long long ull;
using namespace std;

int main() {
    ull n, p;
    cin >> n >> p;
    vector<ull> s(n);
    for(int i = 0; i < n; ++i) cin >> s[i];
    int maxsize = 0;
    sort(s.begin(), s.end());
    for(int i = 0; i < n; ++i) {
        for(int j = i + maxsize; j < n; ++j) {
            if(s[i] * p >= s[j]) {
                if(maxsize < j - i + 1)
                    maxsize = j - i + 1;
            }
            else
                break;
        }
    }
    cout << maxsize;
    return 0;
}