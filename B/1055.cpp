#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct p {
    string name;
    int h;
};

bool cmp(p &a, p &b){
    if(a.h == b.h)
        return a.name < b.name;
    else
        return a.h > b.h;
}

int main() {
    int n, k, col, mcol;
    cin >> n >> k;
    mcol = n / k + n % k;
    col = n / k;
    vector<p> ps(n);
    for(int i = 0; i < n; ++i) cin >> ps[i].name >> ps[i].h;
    sort(ps.begin(), ps.end(), cmp);
    for(int i = 0; i < n;) {
        int gap = 1, dir = 1, c;
        if(i == 0) c = mcol;
        else c = col;
        vector<string> row;
        for(int j = i; j < i + c; ++j) {
            if(j == i) row.emplace_back(ps[j].name);
            else {
                if(dir > 0) row.insert(row.begin(), ps[j].name);
                else row.emplace_back(ps[j].name);
                dir *= -1;
            }
        }
        i += c;
        for(int j = 0; j < c; ++j)
            printf("%s%s%s", (j != 0 ? " " : ""), row[j].c_str(), (j == c - 1 ? "\n" : ""));
    }
    return 0;
}
