#include <bits/stdc++.h>
using namespace std;

int railways[1001][1001] = {0};
bool visit[1001];

void dfs(int start, int n) {
    visit[start] = true;
    for(int i = 1; i <= n; ++i) {
        if(railways[start][i] == 1 && !visit[i] && i != start)
            dfs(i, n);
    }
}

int main() {
    int n, m, k, i, j, l, check, cnt;
    scanf("%d %d %d", &n, &m, &k);
    for(i = 0; i < m; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        railways[from][to] = railways[to][from] = 1;
    }
    for(i = 0; i < k; ++i) {
        fill(visit, visit + 1001, false);
        cnt = 0;

        scanf("%d", &check);
        visit[check] = true;
        for(j = 1; j <= n; ++j) {
            if(visit[j]) continue;
            dfs(j, n);
            cnt++;
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}