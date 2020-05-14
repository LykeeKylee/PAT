#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    int left;
    int right;
};

int post[35], in[35];
vector<node> tree;

int findx(int low, int high, int x) {
    for(int i = low; i <= high; ++i) {
        if(in[i] == x) return i;
    }
}

int get_tree(int plow, int phigh, int ilow, int ihigh) {
    if(plow > phigh) return -1;
    int x = post[phigh];
    node root{x, -1, -1};
    int pos = findx(ilow, ihigh, x);
    int leftsize = pos - ilow, rightsize = ihigh - pos;
    root.left = get_tree(plow, plow + leftsize - 1, ilow, pos - 1);
    root.right = get_tree(plow + leftsize, plow + leftsize + rightsize - 1, pos + 1, ihigh);
    tree.emplace_back(root);
    return tree.size() - 1;
}

int main() {
    int n, i;
    cin >> n;
    if(n > 0) {
        for(i = 1; i <= n; ++i) cin >> post[i];
        for(i = 1; i <= n; ++i) cin >> in[i];
        int head = get_tree(1, n, 1, n);
        queue<int> dfs;
        dfs.push(head);
        bool flag = true;
        while(!dfs.empty()) {
            int r = dfs.front();
            dfs.pop();
            printf("%s%d", (flag ? "" : " "), tree[r].x);
            flag = false;
            if(tree[r].left != -1) dfs.push(tree[r].left);
            if(tree[r].right != -1) dfs.push(tree[r].right);
        }
    }
    return 0;
}