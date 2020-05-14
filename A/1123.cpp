#include<bits/stdc++.h>
using namespace std;
struct node {
    int num, lh, rh, left, right;
};
vector<node> btree;
int get_height(int root) {
    if (root == -1) return 0;
    int lh = get_height(btree[root].left), rh = get_height(btree[root].right);
    btree[root].lh = lh;
    btree[root].rh = rh;
    return max(lh, rh) + 1;
}
int LL(int root) {
    int leftn = btree[root].left;
    btree[root].left = btree[leftn].right;
    btree[leftn].right = root;
    return leftn;
}
int RR(int root) {
    int rightn = btree[root].right;
    btree[root].right = btree[rightn].left;
    btree[rightn].left = root;
    return rightn;
}
int LR(int root) {
    btree[root].left = RR(btree[root].left);
    return LL(root);
}
int RL(int root) {
    btree[root].right = LL(btree[root].right);
    return RR(root);
}
int insert(int root, node x) {
    if (root == -1) {
        btree.emplace_back(x);
        return btree.size() - 1;
    }
    if (x.num < btree[root].num) {
        int xx = insert(btree[root].left, x);
        btree[root].left = xx;
    } else {
        int xx = insert(btree[root].right, x);
        btree[root].right = xx;
    }
    btree[root].lh = get_height(btree[root].left);
    btree[root].rh = get_height(btree[root].right);
    if (btree[root].lh - btree[root].rh > 1) {
        int ln = btree[root].left;
        if (btree[ln].lh > btree[ln].rh) root = LL(root);
        else root = LR(root);
    } else if (btree[root].rh - btree[root].lh > 1) {
        int rn = btree[root].right;
        if (btree[rn].rh > btree[rn].lh) root = RR(root);
        else root = RL(root);
    }
    btree[root].lh = get_height(btree[root].left);
    btree[root].rh = get_height(btree[root].right);
    return root;
}
int main() {
    int n, i, j, x, y, head = -1, flag = 1;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        node t{x, 0, 0, -1, -1};
        head = insert(head, t);
    }
    queue<int> q;
    vector<int> ctree(1, n);
    q.push(head);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ctree.emplace_back(btree[t].num);
        if (btree[t].left != -1) q.push(btree[t].left);
        if (btree[t].right != -1) q.push(btree[t].right);
    }
    bool c = true;
    for (i = 1; i <= n; ++i) {
        printf("%s%d", (flag == 0 ? " " : ""), ctree[i]);
        flag = 0;
        if(2 * i <= n && ctree[i] < ctree[2 * i]) c = false;
        if(2 * i + 1 <= n && ctree[i] > ctree[2 * i + 1]) c = false;
    }
    cout << endl << (c ? "YES":"NO");
    return 0;
}
