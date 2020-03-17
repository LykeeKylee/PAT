#include <bits/stdc++.h>
using namespace std;

struct window {
    int no;
    int minutes;
};

bool operator< (const window a, const window b) {
    if(a.minutes == b.minutes) return a.no > b.no;
    return a.minutes > b.minutes;
}

int processTime[1005], leftTime[1005];

int main() {

//    priority_queue<window> w;
//    w.push({1, 1});
//    w.push({2, 2});
//    w.push({3, 2});
//    w.push({4, 4});
//    w.push({5, 1});
//
//    while(!w.empty()) {
//        window f = w.top();
//        w.pop();
//        cout << f.no << ' ' << f.minutes << endl;
//    }

    int win, cap, cus, cusq, i, j, k;
    queue<int> waiting[22], left;
    cin >> win >> cap >> cus >> cusq;
    vector<int> query(cusq);
    int x = 1;
    for(i = 1; i <= cus; ++i) {
        cin >> processTime[i];
        if(i <= win * cap) {
            waiting[x++].push(i);
            if(x > win) x = 1;
        }
        else {
            left.push(i);
        }
    }

    priority_queue<window> w;
    for(i = 1; i <= win; ++i) {
        window t{i, 0};
        w.push(t);
    }

    while(cus > 0) {
        window tp = w.top();
        w.pop();

        int no = tp.no;
        if(!waiting[no].empty()) {
            int person = waiting[no].front();
            waiting[no].pop();
            --cus;
            leftTime[person] = tp.minutes = tp.minutes + processTime[person];
            w.push(tp);
//            cout << "person: " << person << endl;
//            cout << tp.no << ' ' << tp.minutes << endl;
        }

        if(!left.empty() && waiting[w.top().no].size() < cap) {
            int app = left.front();
//            cout << "append: " << app << endl;
            left.pop();
            waiting[w.top().no].push(app);
        }
    }

    int q, hh, mm;
    for(i = 0; i < cusq; ++i) {
        cin >> q;
        int ti = leftTime[q] - processTime[q];
        hh = 8 + leftTime[q] / 60;
        mm = leftTime[q] % 60;

        if(ti >= 540) printf("Sorry\n");
        else printf("%02d:%02d\n", hh, mm);
    }

    return 0;
}