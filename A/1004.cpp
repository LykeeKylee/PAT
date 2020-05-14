#include <bits/stdc++.h>
using namespace std;

vector<int> family[105];
int cnt[105], max_depth = -1, flag[105];

//deep first search
void dfs(int root, int depth) {
    int s = family[root].size();
    if(s == 0) {
        cnt[depth]++;
        max_depth = max(depth, max_depth);
        return;
    }
    else {
        for(int i = 0; i < s; ++i) {
            dfs(family[root][i], depth + 1);
        }
        return;
    }
}

//breadth first search
void bfs(int root) {
    int depth = 1;
    flag[depth] = 1;
    queue<int> query;
    int r, nodecnt = 0;
    query.push(root);
    while(!query.empty()) {
        r = query.front();
        nodecnt++;
        query.pop();

        if(family[r].empty()) {
            cnt[depth]++;
        }
        else {
            int size = family[r].size();
            flag[depth + 1] += size;
            for(int i = 0; i < size; ++i)
                query.push(family[r][i]);
        }

        if(nodecnt == flag[depth]) {
            nodecnt = 0;
            max_depth = max(depth, max_depth);
            depth++;
        }
    }
}

int main() {
    int n, m, i, j;
    fill(cnt, cnt + 105, 0);
    cin >> n >> m;
    if(n != 0) {
        for(i = 0; i < m; ++i) {
            int parent, size, c;
            cin >> parent >> size;
            for(j = 0; j < size; ++j) {
                cin >> c;
                family[parent].emplace_back(c);
            }
        }

//        dfs(1, 1);
        bfs(1);
        for(i = 1; i <= max_depth; ++i)
            printf("%s%d", (i == 1 ? "" : " "), cnt[i]);
    }
    return 0;
}


