#include <bits/stdc++.h>
using namespace std;

int Tolower(int c) {
    return tolower(c);
}

struct college {
    string name;
    int stu;
    double fenshu;
};

double gradeswitch(string &id, double grade) {
    switch (id[0]) {
        case 'A': return grade;
        case 'B': return grade / 1.5;
        case 'T': return grade * 1.5;
    }
}

bool cmp(college &a, college &b) {
    int af = floor(a.fenshu), bf = floor(b.fenshu);
    if(af == bf) {
        if(a.stu == b.stu) return a.name < b.name;
        else return a.stu < b.stu;
    }
    return af > bf;
}

int main() {
    int n, scnt = 0, rank = 1, same = 1;
    cin >> n;
    map<string, int> hash;
    vector<college> clg(1);
    string id, sc;
    double gd;
    for(int i = 0; i < n; ++i) {
        cin >> id >> gd >> sc;
        transform(sc.begin(), sc.end(), sc.begin(), Tolower);
        if(hash[sc] == 0) {
            hash[sc] = ++scnt;
            college t = {sc, 1, gradeswitch(id, gd)};
            clg.emplace_back(t);
        }
        else {
            clg[hash[sc]].stu++;
            clg[hash[sc]].fenshu += gradeswitch(id, gd);
        }
    }
    sort(clg.begin() + 1, clg.end(), cmp);
    cout << scnt << endl;
    for(int i = 1; i <= scnt; ++i) {
        printf("%d %s %d %d\n", rank, clg[i].name.c_str(), int(floor(clg[i].fenshu)), clg[i].stu);
        if(i <= scnt - 1 && int(floor(clg[i].fenshu)) > int(floor(clg[i + 1].fenshu))) {
            rank += same;
            same = 1;
        }
        else if(i <= scnt - 1 && int(floor(clg[i].fenshu)) == int(floor(clg[i + 1].fenshu))) same++;
    }
    return 0;
}