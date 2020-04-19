#include <iostream>
#include <stack>

using namespace std;

struct node {
    int x;
    node *left{};
    node *right{};

    node(int data, node *l, node *r) : x(data), left(l), right(r) {
    }
};

node *create(int x, int n) {
    if (x > n) return nullptr;
    node *left = create(2 * x, n), *right = create(2 * x + 1, n);
    node *root = new node(x, left, right);
    return root;
}

void preorder_recursive(node *root) {
    if (!root) return;
    cout << root->x << ' ';
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

void preorder_non_recursive(node *root) {
    if(!root) return;
    stack<node*> s;
    s.push(root);
    while(!s.empty()) {
        node *top = s.top();
        s.pop();
        cout << top->x << ' ';
        if(top->right) s.push(top->right);
        if(top->left) s.push(top->left);
    }
}

void inorder_recursive(node *root) {
    if (!root) return;
    inorder_recursive(root->left);
    cout << root->x << ' ';
    inorder_recursive(root->right);
}

void inorder_non_recursive(node *root) {
    if (!root) return;
    stack<node *> s;
    node *p = root;
    while (!s.empty() || p) {
        if(p) {
            s.push(p);
            p = p->left;
        }
        else {
            p = s.top();
            s.pop();
            cout << p->x << ' ';
            p = p->right;
        }
    }
}

void postorder_recursive(node *root) {
    if (!root) return;
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout << root->x << ' ';
}

void postorder_non_recursive(node *root) {
    if(!root) return ;
    stack<node*> s, out;
    s.push(root);
    while(!s.empty()) {
        node *top = s.top();
        s.pop();
        out.push(top);
        if(out.top()->left) s.push(out.top()->left);
        if(out.top()->right) s.push(out.top()->right);
    }
    while(!out.empty()) {
        node *top = out.top();
        out.pop();
        cout << top->x << ' ';
    }
}

int main() {
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    node *root = create(1, 7);
    cout << "Recursive Traversal" << endl;
    preorder_recursive(root);
    cout << endl;
    inorder_recursive(root);
    cout << endl;
    postorder_recursive(root);
    cout << endl << endl;
    cout << "Non-Recursive Traversal" << endl;
    preorder_non_recursive(root);
    cout << endl;
    inorder_non_recursive(root);
    cout << endl;
    postorder_non_recursive(root);
    return 0;
}
