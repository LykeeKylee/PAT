#include<iostream>
#include<algorithm>

using namespace std;
struct node {
    int x, y;
};
struct structcmp {
    bool operator() (node &a, node &b) {
        return a.x < b.x;
    }
}structcmp;
bool cmp(node &a, node &b) {
    return a.x < b.x;
}
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    cout << "pos: " << max_element(a, a + 5) << endl;
    cout << "max: "<< *max_element(a, a + 5) << endl << endl;

    node s[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << "pos: " << max_element(s, s + 3, cmp) << endl;
    cout << "pos: " << max_element(s, s + 3, structcmp) << endl;
    cout << "pos: " << (*max_element(s, s + 3, cmp)).x << ' ' << (*max_element(s, s + 3, cmp)).y << endl;
    return 0;
}