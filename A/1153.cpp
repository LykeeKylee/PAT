#include <bits/stdc++.h>
using namespace std;

struct testee {
    string card;
    char type;
    int site;
    int date;
    int number;
    int grade;
};

bool cmp(testee &a, testee &b) {
    if(a.grade == b.grade) return a.card < b.card;
    return a.grade > b.grade;
}

bool cmp1(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n, m, i, grade;
    string cardid;
    cin >> n >> m;
    map<char, vector<testee>> all_testees;
    map<int, pair<int, int>> siteCnt;
    map<int, map<int, int>> dateCnt;
    for(i = 0; i < n; ++i) {
        cin >> cardid >> grade;
        testee tmp{cardid,
                   cardid[0],
                   atoi(cardid.substr(1, 3).c_str()),
                   atoi(cardid.substr(4, 6).c_str()),
                   atoi(cardid.substr(10, 3).c_str()),
                   grade};
        all_testees[tmp.type].emplace_back(tmp);
        siteCnt[tmp.site].first++;
        siteCnt[tmp.site].second += tmp.grade;
        dateCnt[tmp.date][tmp.site]++;
    }
    for(i = 1; i <= m; ++i) {
        int query;
        string term;
        cin >> query >> term;
        printf("Case %d: %d %s\n", i, query, term.c_str());
        switch (query) {
            case 1: {
                char q = term[0];
                if(all_testees.find(q) == all_testees.end())
                    printf("%s\n", "NA");
                else {
                    vector<testee> *ptr =  &all_testees[q];
                    sort(ptr->begin(), ptr->end(), cmp);
                    for(auto t = ptr->begin(); t != ptr->end(); ++t)
                        printf("%s %d\n", t->card.c_str(), t->grade);
                }
                break;
            }
            case 2: {
                int q = atoi(term.c_str());
                if(siteCnt.find(q) == siteCnt.end())
                    printf("%s\n", "NA");
                else {
                    printf("%d %d\n", siteCnt[q].first, siteCnt[q].second);
                }
                break;
            }
            case 3: {
                int q = atoi(term.c_str());
                if(dateCnt.find(q) == dateCnt.end())
                    printf("%s\n", "NA");
                else {
                    vector<pair<int, int>> vp;
                    map<int, int> x = dateCnt[q];
                    for(auto t = x.begin(); t != x.end(); ++t) {
                        pair<int, int> tmp(t->first, t->second);
                        vp.emplace_back(tmp);
                    }
                    sort(vp.begin(), vp.end(), cmp1);
                    for(auto t = vp.begin(); t != vp.end(); ++t)
                        printf("%03d %d\n", t->first, t->second);
                }
                break;
            }
            default:
                printf("%s\n", "NA");
        }
    }
    return 0;
}