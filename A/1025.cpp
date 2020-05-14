#include <bits/stdc++.h>
using namespace std;

struct testee {
    string id;
    int grade;
    int location;
    int local_rank;
    int final_rank;
};

testee eachRank[100 * 300 + 5];

bool cmp(testee &a, testee &b) {
    if(a.grade == b.grade) return a.id < b.id;
    return a.grade > b.grade;
}

int main() {
    int n, k, i, j, cnt = 0;
    cin >> n;
    for(i = 1; i <= n; ++i) {
        cin >> k;
        for(j = 0; j < k; ++j) {
            cin >> eachRank[cnt].id >> eachRank[cnt].grade;
            eachRank[cnt++].location = i;
        }
        sort(eachRank + cnt - k, eachRank + cnt, cmp);
    }
    int currank, curlocation = -1, curgrade, offset;
    for(i = 0; i < cnt; ++i) {
        if(eachRank[i].location != curlocation) {
            currank = 1;
            curlocation = eachRank[i].location;
            offset = 0;
            curgrade = eachRank[i].grade;
        }
        if(eachRank[i].grade == curgrade) {
            eachRank[i].local_rank = currank;
            ++offset;
        }
        else {
            eachRank[i].local_rank = currank + offset;
            currank += offset;
            offset = 1;
            curgrade = eachRank[i].grade;
        }
    }
    sort(eachRank, eachRank + cnt, cmp);
    currank = 1;
    offset = 0;
    curgrade = eachRank[0].grade;
    for(i = 0; i < cnt; ++i) {
        if(eachRank[i].grade == curgrade) {
            eachRank[i].final_rank = currank;
            ++offset;
        }
        else {
            eachRank[i].final_rank = currank + offset;
            currank += offset;
            offset = 1;
            curgrade = eachRank[i].grade;
        }
    }
    cout << cnt << endl;
    for(i = 0; i < cnt; ++i) {
        printf("%s %d %d %d\n", eachRank[i].id.c_str(), eachRank[i].final_rank, eachRank[i].location, eachRank[i].local_rank);
    }
    return 0;
}