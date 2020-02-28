#include <bits/stdc++.h>
using namespace std;

bool check(map<int, vector<int>> &a, int &x, int seq[], int &k) {
    if(a.find(x) == a.end())
        return true;
    vector<int> list = a[x];
    for(int i = 0; i < list.size(); ++i) {
        if(find(seq, seq + k, list[i]) != seq + k)
            return false;
    }
    return true;
}

int main() {
    int n, m, x, y, k;
    cin >> n >> m;
    map<int, vector<int>> list;
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        list[x].emplace_back(y);
        list[y].emplace_back(x);
    }
    for(int i = 0; i < m; ++i) {
        cin >> k;
        int *seq = new int[k], flag = 1;
        for(int j = 0; j < k; ++j) cin >> seq[j];
        for(int j = 0; j < k; ++j) {
            if(!check(list, seq[j], seq, k)) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
        delete[]seq;
    }
    return 0;
}