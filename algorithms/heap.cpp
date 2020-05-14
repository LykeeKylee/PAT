#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
bool max_cmp(int &a, int &b) {
    return a > b;
}

bool min_cmp(int &a, int &b) {
    return a < b;
}

// If the sequence starts from 1, the left child is 2 * i and the right child is 2 * i + 1.
// If the sequence starts from 0, the left child is 2 * i + 1 and the right child 2 * i + 2.

void shiftUp(int node, vector<int> &v, bool (*cmp)(int &a, int &b)) {
    int root = (node - 1) / 2;
    if(root >= 0 && cmp(v[node], v[root])) {
        swap(v[node], v[root]);
        shiftUp(root, v, cmp);
    }
}

void shiftDown(int root, vector<int> &v, bool (*cmp)(int &a, int &b), int n) {
    int left = 2 * root + 1, right = 2 * root + 2, size = n, next;
    if(left < size && right < size) next = cmp(v[left], v[right]) ? left : right;
    else if(left < size) next = left;
    else next = -1;
    if(next != -1 && cmp(v[next], v[root])) {
        swap(v[next], v[root]);
        shiftDown(next, v, cmp, n);
    }
}

void insert(int num, vector<int> &v, bool (*cmp)(int &a, int &b)) {
    v.emplace_back(num);
    shiftUp(v.size() - 1, v, cmp);
}

void remove(vector<int> &v, bool (*cmp)(int &a, int &b)) {
    swap(v.front(), v.back());
    v.pop_back();
    shiftDown(0, v, cmp, v.size());
}

void remove(int index, vector<int> &v, bool (*cmp)(int &a, int &b)) {
    if(index >= v.size()) return;
    swap(v[index], v.back());
    v.pop_back();
    shiftDown(index, v, cmp, v.size());
}

void display(vector<int> &v) {
    for(int i : v) cout << i << ' ';
    cout << endl;
}

void heapify(vector<int> &v, bool (*cmp)(int &, int &)) {
    for(int i = v.size() - 1; i >= 0; --i) shiftUp(i, v, cmp);
}

void heapSort(vector<int> &v, int size, bool (*cmp)(int &, int &)) {
    while(size > 0) {
        swap(v.front(), v[size - 1]);
        shiftDown(0, v, cmp, size - 1);
        --size;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v;
    for(int i : a) insert(i, v, max_cmp);
    display(v);
    remove(v, max_cmp);
    display(v);
    remove(2, v, max_cmp);
    display(v);
    cout << endl;
    vector<int> v2(a, a + 7);
    heapify(v2, max_cmp);
    display(v2);
    heapSort(v2, v2.size(), max_cmp);
    display(v2);
    return 0;
}