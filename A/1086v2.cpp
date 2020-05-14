#include <bits/stdc++.h>
using namespace std;
vector<int> inorder, preorder;
bool flag = true;
void postorder(int root, int low, int high) {
    if(low > high) return;
    int mid = preorder[root], pos = low;
    while(pos <= high && inorder[pos] != mid) ++pos;
    postorder(root + 1, low, pos - 1);
    postorder(root + pos - low + 1, pos + 1, high);
    printf("%s%d", flag ? "" : " ", preorder[root]);
    flag = false;
}
int main() {
    int n, i, x;
    string op;
    stack<int> s;
    scanf("%d", &n);
    for(i = 0; i < 2 * n; ++i) {
        cin >> op;
        if(op.length() == 4) {
            cin >> x;
            preorder.emplace_back(x);
            s.push(x);
        }
        else {
            inorder.emplace_back(s.top());
            s.pop();
        }
    }
    postorder(0, 0, n - 1);
    return 0;
}