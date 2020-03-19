#include <bits/stdc++.h>
#define ON 1
#define OFF 2
using namespace std;

struct call {
    int momo;
    int dd;
    int hh;
    int mm;
    int time;
    int status;
};

struct record {
    int d1;
    int h1;
    int m1;
    int d2;
    int h2;
    int m2;
    int time;
    double total;
};

int charge[24];

bool cmp(call &a, call &b) {
    return a.time < b.time;
}

int main() {
    int n, i, j;
    for(i = 0; i < 24; ++i) cin >> charge[i];
    cin >> n;

    map<string, vector<call>> cus;
    string name, status;
    int momo, dd, hh, mm, time;
    for(i = 0; i < n; ++i) {
        cin >> name;
        scanf("%d:%d:%d:%d", &momo, &dd, &hh, &mm);
        cin >> status;
        time = dd * 24 * 60 + hh * 60 + mm;
        call tmp{momo, dd, hh, mm, time, (status == "on-line" ? ON : OFF)};
        cus[name].emplace_back(tmp);
    }

    for(auto k = cus.begin(); k != cus.end(); ++k) {
        sort(k->second.begin(), k->second.end(), cmp);

        double total = 0, each_total = 0;
        vector<record> vr;

        for(auto t = k->second.begin(); t != k->second.end(); ++t) {
            if(t->status == OFF) continue;

            auto next = t + 1;
            if(next != k->second.end() && next->status == OFF && next->momo == t->momo) {
                each_total = 0;
                int sdd = t->dd, shh = t->hh, smm = t->mm;
                while(sdd != next->dd || shh != next->hh || smm != next->mm) {
                    each_total += charge[shh];
                    smm++;
                    if(smm >= 60) {
                        smm = 0;
                        shh++;
                        if(shh >= 24) {
                            shh = 0;
                            sdd++;
                        }
                    }
                }
                record tmp{t->dd, t->hh, t->mm, next->dd, next->hh, next->mm, next->time - t->time, (each_total * 1.0) / 100.0};
                vr.emplace_back(tmp);

                total += (each_total * 1.0) / 100.0;
            }
        }
        if(!vr.empty() && total != 0.0) {
            printf("%s %02d\n", k->first.c_str(), k->second[0].momo);
            for(auto z = vr.begin(); z != vr.end(); ++z) {
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%0.2lf\n", z->d1, z->h1, z->m1, z->d2, z->h2, z->m2, z->time, z->total);
            }
            printf("Total amount: $%0.2lf\n", total);
        }

    }
    return 0;
}