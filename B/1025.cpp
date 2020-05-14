#include <iostream>
#include <algorithm>
#define MAX_SIZE 100005
using namespace std;

int main() {
    int n, k, head, data[MAX_SIZE], next[MAX_SIZE], p, seq[MAX_SIZE];
    cin >> head >> n >> k;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        cin >> data[t] >> next[t];
    }
    p = head;
    //todo: 离散在链表外的节点！！！！！
    int cnt = 0;
    while(p != -1) {
        seq[cnt++] = p;
        p = next[p];
    }
    for(int i = 0; i < (cnt - cnt % k); i += k)
        reverse(seq + i, seq + i + k);
    for(int i = 0; i < cnt - 1; ++i) {
        printf("%05d %d %05d\n", seq[i], data[seq[i]], seq[i + 1]);
    }
    printf("%05d %d -1", seq[cnt - 1], data[seq[cnt - 1]]);
    return 0;
}