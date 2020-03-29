//preorder:  5, 3, 7, 2, 6, 4, 8, 1
//inorder:   7, 2, 3, 4, 6, 5, 1, 8
//postorder: 2, 7, 4, 6, 3, 1, 8, 5

// BST
// preorder:  6, 3, 1, 2, 5, 4, 8, 7
// inorder:   1, 2, 3, 4, 5, 6, 7, 8
// postorder: 2, 1, 4, 5, 3, 7, 8, 6

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int preorder[] = {5, 3, 7, 2, 6, 4, 8, 1},
        inorder[] = {7, 2, 3, 4, 6, 5, 1, 8},
        postorder[] = {2, 7, 4, 6, 3, 1, 8, 5};
map<int, int> Hash;
int bst_preorder[] = {6, 3, 1, 2, 5, 4, 8, 7},
        bst_inorder[] = {1, 2, 3, 4, 5, 6, 7, 8},
        bst_postorder[] = {2, 1, 4, 5, 3, 7, 8, 6};

void toPostOrder(int low, int high, int root) {
    if (low > high) return;
    int pos = Hash[preorder[root]];
    toPostOrder(low, pos - 1, root + 1);
    toPostOrder(pos + 1, high, root + pos - low + 1);
    cout << preorder[root] << ' ';
}

void toPreOrder(int low, int high, int root) {
    if (low > high) return;
    int pos = Hash[postorder[root]];
    cout << postorder[root] << ' ';
    toPreOrder(low, pos - 1, root - (high - pos) - 1);
    toPreOrder(pos + 1, high, root - 1);
}

void bst_pre_to(int low, int high, string mode = "in") {
    if (low > high) return;
    int root = bst_preorder[low], mid = high + 1;
    for (int i = low + 1; i <= high; ++i) {
        if (root < bst_preorder[i]) {
            mid = i;
            break;
        }
    }
    bst_pre_to(low + 1, mid - 1, mode);
    if (mode == "in") cout << root << ' ';
    bst_pre_to(mid, high, mode);
    if (mode == "post") cout << root << ' ';
}

void bst_post_to(int low, int high, string mode = "in") {
    if (low > high) return;
    int root = bst_postorder[high], mid = high;
    for (int i = low; i <= high - 1; ++i) {
        if (root < bst_postorder[i]) {
            mid = i;
            break;
        }
    }
    if (mode == "pre") cout << root << ' ';
    bst_post_to(low, mid - 1, mode);
    if (mode == "in") cout << root << ' ';
    bst_post_to(mid, high - 1, mode);
}

// create the tree if you know the preorder sequence and the inorder sequence
struct node {
    int x;
    int left;
    int right;
};
vector<node> btree;

int create(int low, int high, int root) {
    if (low > high) return -1;
    int pos = Hash[preorder[root]], right, left;
    left = create(low, pos - 1, root + 1);
    right = create(pos + 1, high, root + pos - low + 1);
    node tmp{preorder[root], left, right};
    btree.emplace_back(tmp);
    return btree.size() - 1;
}

void bfs() {
    int root = create(0, 7, 0);
    queue<int> seq;
    seq.push(root);
    while (!seq.empty()) {
        int t = seq.front();
        seq.pop();
        cout << btree[t].x << ' ';
        if (btree[t].left != -1) seq.push(btree[t].left);
        if (btree[t].right != -1) seq.push(btree[t].right);
    }
}

int main() {
    for (int i = 0; i < 8; ++i) Hash[inorder[i]] = i;
    cout << "To PostOrder: ";
    toPostOrder(0, 7, 0);
    cout << endl << "To PreOrder: ";
    toPreOrder(0, 7, 7);

    cout << endl << endl << "BST PreOrder to InOrder: ";
    bst_pre_to(0, 7, "in");
    cout << endl << "BST PreOrder to PostOrder: ";
    bst_pre_to(0, 7, "post");
    cout << endl << "BST PostOrder to InOrder: ";
    bst_post_to(0, 7, "in");
    cout << endl << "BST PostOrder to PreOrder: ";
    bst_post_to(0, 7, "pre");

    cout << endl << endl << "Create the tree and output the level traversal sequence: ";
    bfs();
}