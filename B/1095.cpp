#include <bits/stdc++.h>
using namespace std;

struct stu {
    string idstr;
    char type;
    int kc;
    int date;
    int id;
    int grade;
};

struct kcinfo {
    int person;
    int allgrade;
};

struct dateinfo {
    int kc;
    int cnt;
};

bool cmp(stu &a, stu &b) {
    //todo:注意这是一种错误的形式
//    if(a.grade == b.grade) return a.kc < b.kc || a.date < b.date || a.id < b.id;
    if(a.grade == b.grade) return a.idstr < b.idstr;
    return a.grade > b.grade;
}

bool cmp1(dateinfo &a, dateinfo &b) {
    if(a.cnt == b.cnt) return a.kc < b.kc;
    return a.cnt > b.cnt;
}

vector<stu> t, a, b;
kcinfo kaochang[1020];
map<int, vector<dateinfo>> datecnt;
map<char, vector<stu>*> typehash;

int main() {
    int n, m, grade, cmd;
    memset(kaochang, 0, sizeof(kaochang));
    typehash['A'] = &a;
    typehash['T'] = &t;
    typehash['B'] = &b;
    cin >> n >> m;
    string id;
    for(int i = 0; i < n; ++i) {
        cin >> id >> grade;
        stu tmp;
        tmp.idstr = id;
        tmp.type = id[0];
        tmp.kc = atoi(id.substr(1, 3).c_str());
        tmp.date = atoi(id.substr(4, 6).c_str());
        tmp.id = atoi(id.substr(10, 3).c_str());
        tmp.grade = grade;
        typehash[tmp.type]->emplace_back(tmp);
        kaochang[tmp.kc].person++;
        kaochang[tmp.kc].allgrade += tmp.grade;
        int pos = -1;
        dateinfo d;
        if(datecnt.find(tmp.date) == datecnt.end()) {
            d.kc = tmp.kc;
            d.cnt = 1;
            datecnt[tmp.date].emplace_back(d);
        }
        else {
            for(int j = 0; j < datecnt[tmp.date].size(); ++j) {
                if(datecnt[tmp.date][j].kc == tmp.kc) {
                    pos = j;
                    break;
                }
            }
            if(pos == -1) {
                d.kc = tmp.kc;
                d.cnt = 1;
                datecnt[tmp.date].emplace_back(d);
            }
            else datecnt[tmp.date][pos].cnt++;
        }

    }
    for(int j = 0; j < m; ++j) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                char tp;
                cin >> tp;
                printf("Case %d: %d %c\n", j + 1, cmd, tp);
                if(typehash.find(tp) == typehash.end()) cout << "NA" << endl;
                else {
                    vector<stu> *ptr = typehash[tp];
                    if(ptr->empty()) {
                        cout << "NA" << endl;
                        break;
                    }
                    sort(ptr->begin(), ptr->end(), cmp);
                    for(int i = 0; i < ptr->size(); ++i) {
                        printf("%c%03d%06d%03d %d\n", (*ptr)[i].type, (*ptr)[i].kc, (*ptr)[i].date, (*ptr)[i].id, (*ptr)[i].grade);
                    }
                }
                break;
            }
            case 2: {
                int k;
                cin >> k;
                printf("Case %d: %d %03d\n", j + 1, cmd, k);
                if(k > 999 || k < 101) cout << "NA" << endl;
                else if(kaochang[k].person == 0) cout << "NA" << endl;
                else {
                    printf("%d %d\n", kaochang[k].person, kaochang[k].allgrade);
                }
                break;
            }
            case 3: {
                int date;
                cin >> date;
                printf("Case %d: %d %06d\n", j + 1, cmd, date);
                if(datecnt.find(date) == datecnt.end()) cout << "NA" << endl;
                else {
                    sort(datecnt[date].begin(), datecnt[date].end(), cmp1);
                    for(int i = 0; i < datecnt[date].size(); ++i)
                        printf("%03d %d\n", datecnt[date][i].kc, datecnt[date][i].cnt);
                }
                break;
            }
        }
    }
    return 0;
}