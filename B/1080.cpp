#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct grade {
    string name;
    double bc = -1;
    double mid = -1;
    double fianl = -1;
    double zong = -1;
};

bool cmp(grade &a, grade &b) {
    if(round(a.zong) == round(b.zong)) return a.name < b.name;
    return round(a.zong) > round(b.zong);
}

int main() {
    int p, m, n, cnt;
    cin >> p >> m >> n;
    string name;
    vector<grade> seq;
    map<string, grade> grademap;
    for(int i = 0; i < p + m + n; ++i) {
        cin >> name;
        grademap[name].name = name;
        if(i < p) cin >> grademap[name].bc;
        else if(i < p + m) cin >> grademap[name].mid;
        else cin >> grademap[name].fianl;
    }
    for(map<string, grade>::iterator i = grademap.begin(); i != grademap.end(); ++i) {
        if(i->second.bc >= 200.0) {
            if(i->second.mid > i->second.fianl) i->second.zong = 0.4 * i->second.mid + 0.6 * i->second.fianl;
            else i->second.zong = i->second.fianl;
            if(round(i->second.zong) >= 60) seq.emplace_back(i->second);
        }
    }
    sort(seq.begin(), seq.end(), cmp);
    for(int i = 0; i < seq.size(); ++i) {
        printf("%s %d %d %d %d\n", seq[i].name.c_str(), int(seq[i].bc), int(seq[i].mid), int(seq[i].fianl), int(round(seq[i].zong)));
    }
    return 0;
}