#include <bits/stdc++.h>
using namespace std;

int colors[10005];
map<int, int> colorCnt;

int main() {
    int n, m, k, i, j, c, proper, t1, t2, cnt;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> graph(m);
    for(i = 0; i < m; ++i) {
        scanf("%d %d", &t1, &t2);
        graph[i] = make_pair(t1, t2);
    }
    scanf("%d", &k);
    for(i = 0; i < k; ++i) {
        colorCnt.clear();
        proper = 1;
        cnt = 0;
        for(j = 0; j < n; ++j) {
            scanf("%d", colors + j);
            if(colorCnt[colors[j]] == 0) {
                ++cnt;
                colorCnt[colors[j]] = 1;
            }
        }
        for(auto p = graph.begin(); p != graph.end(); ++p) {
            if(colors[p->first] == colors[p->second]) {
                proper = 0;
                break;
            }
        }
        if(proper == 1) printf("%d-coloring\n", cnt);
        else printf("%s\n", "No");
    }
    return 0;
}