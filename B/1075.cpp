#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int head, n, k, cnt = 0, x;
    map<int, int> add;
    cin >> head >> n >> k;
    vector<int> data(n), next(n), seq(n), fushu, xyk, dyk, final;
    for(int i = 0; i < n; ++i) {
        cin >> x >> data[i] >> next[i];
        add[x] = i;
    }
    x = head;
    while(x != -1) {
        seq[cnt++] = x;
        x = next[add[x]];
    }
    for(int i = 0; i < cnt; ++i){
        if(data[add[seq[i]]] < 0) fushu.emplace_back(seq[i]);
        else if(data[add[seq[i]]] <= k) xyk.emplace_back(seq[i]);
        else if(data[add[seq[i]]] > k) dyk.emplace_back(seq[i]);
    }
    final.insert(final.end(), fushu.begin(), fushu.end());
    final.insert(final.end(), xyk.begin(), xyk.end());
    final.insert(final.end(), dyk.begin(), dyk.end());
    for(int i = 0; i < final.size(); ++i) {
        if(i < final.size() - 1)
            printf("%05d %d %05d\n", final[i], data[add[final[i]]], final[i + 1]);
        else
            printf("%05d %d %d", final[i], data[add[final[i]]], -1);
    }
    return 0;
}