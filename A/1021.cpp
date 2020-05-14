#include <bits/stdc++.h>
using namespace std;

int graph[10005][10005] = {0};
vector<int> roots;
int maxdepth = -1, mm = -1;
bool visit[10005];

void dfs(int root, int n, int depth) {
    for(int i = 1; i <= n; ++i) {
        if(visit[i]) continue;
        visit[i] = true;
        if(graph[root][i] == 1) dfs(i, n, depth + 1);
    }
    visit[root] = false;
    if(maxdepth < depth) maxdepth = depth;
}

int main() {
    int n, i;
    cin >> n;
    for(i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }
    roots.resize(n);
    for(i = 1; i <= n; ++i) {
        fill(visit, visit + 10005, false);
        visit[i] = true;
        dfs(i, n, 1);
        roots[i] = maxdepth;
        mm = maxdepth > mm ? maxdepth : mm;
    }
    cout << mm << endl;
    for(i = 1; i <= n; ++i) {
        if(roots[i] == mm)
            printf("%d\n", i);
    }
    return 0;
}