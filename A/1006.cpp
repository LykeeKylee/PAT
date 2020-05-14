#include <bits/stdc++.h>
using namespace std;

struct user {
    string name;
    int sign_in;
    int sign_out;
};

bool cmp_in(user &a, user &b) {
    return a.sign_in < b.sign_in;
}

bool cmp_out(user &a, user &b) {
    return a.sign_out > b.sign_out;
}

int main() {
    int m, hh, mm, ss;
    string name;
    cin >> m;
    vector<user> query(m);
    for(int i = 0; i < m; ++i) {
        cin >> query[i].name;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        query[i].sign_in = hh * 60 * 60 + mm * 60 + ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        query[i].sign_out = hh * 60 * 60 + mm * 60 + ss;
    }
    sort(query.begin(), query.end(), cmp_in);
    cout << query.front().name << " ";
    sort(query.begin(), query.end(), cmp_out);
    cout << query.front().name;
    return 0;
}