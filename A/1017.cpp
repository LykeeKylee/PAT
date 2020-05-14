#include <bits/stdc++.h>
using namespace std;

struct transaction {
    int arrive;
    int cost;
    friend bool operator< (transaction a, transaction b) { return a.arrive > b.arrive; }
};

int main() {
    int cus, win, i, j;
    cin >> cus >> win;
    priority_queue<transaction> tc;
    for(i = 0; i < cus; ++i) {
        int hh, mm, ss, pp, convert;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &pp);
        convert = hh * 60 * 60 + mm * 60 + ss;
        if(convert >= 17 * 60 * 60 + 1) continue;
        transaction tmp{convert, pp * 60};
        tc.push(tmp);
    }
    cus = tc.size();
    priority_queue<int, vector<int>, greater<int>> waiting;
    for(i = 0; i < win; ++i) waiting.push(8 * 60 * 60);
    double total_waiting = 0;
    while(!tc.empty()) {
        transaction ncus = tc.top();
        tc.pop();
        int serve = waiting.top();
        waiting.pop();
        if(serve >= ncus.arrive) total_waiting += (serve - ncus.arrive);
        else serve = ncus.arrive;
        serve += ncus.cost;
        waiting.push(serve);
    }
    printf("%0.1lf", total_waiting / 60.0 / cus);
    return 0;
}