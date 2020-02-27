#include <bits/stdc++.h>
using namespace std;

int main() {
    int coupleA[100005], coupleB[100005], guest[10005], single[10005], n, m, x, y, cnt = 0;
    memset(coupleA, -1, sizeof(coupleA));
    memset(coupleB, -1, sizeof(coupleB));
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        coupleA[x] = y;
        coupleB[y] = x;
    }
    cin >> m;
    for(int i = 0; i < m; ++i) cin >> guest[i];
    if(m == 1)
        cout << m << endl << guest[0];
    else {
        for(int i = 0; i < m; ++i) {
            if(coupleA[guest[i]] == -1 && coupleB[guest[i]] == -1)
                single[cnt++] = guest[i];
            else {
                int c = (coupleA[guest[i]] == -1 ? coupleB[guest[i]] : coupleA[guest[i]]);
//                if((i == 0 && guest[i + 1] != c) || (i == m - 1 && guest[i - 1] != c) || (guest[i - 1] != c && guest[i + 1] != c)) {
//                    single[cnt++] = guest[i];
//                }
                if(find(guest, guest + m, c) == guest + m) {
                    single[cnt++] = guest[i];
                }
            }
        }
        cout << cnt << (cnt != 0 ? "\n" : "");
        sort(single, single + cnt);
        for(int i = 0; i < cnt; ++i)
            printf("%s%05d%s", (i != 0 ? " " : ""), single[i], (i == cnt - 1 ? "\n" : ""));
    }
    return 0;
}