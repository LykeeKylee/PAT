#include <bits/stdc++.h>
using namespace std;

struct player {
    int arrive_time;
    int play_time;
    int serving_time;
    int waiting_time;
};
struct table {
    int id;
    int time;
    int tag;
};
bool operator < (table a, table b) {
    if(a.time == b.time) return a.id > b.id;
    return a.time > b.time;
}
bool operator < (player a, player b) { return a.arrive_time > b.arrive_time; }
// find the vip table at that time
table find_vip(priority_queue<table> &tennis, table tt) {
    vector<table> temp;
    table next;
    while(tt.tag != 1 && !tennis.empty()) {
        next = tennis.top();
        tennis.pop();
        if(next.tag == 1 && next.time == tt.time) {
            temp.emplace_back(tt);
            tt.tag = next.tag;
            tt.time = next.time;
            tt.id = next.id;
            break;
        }
        else if(next.time > tt.time) {
            temp.emplace_back(next);
            break;
        }
        else if(next.time == tt.time) temp.emplace_back(next);
    }
    for(auto p = temp.begin(); p != temp.end(); ++p) tennis.push(*p);
    return tt;
}

int main() {
    int n, k, m, i, served[105];
    priority_queue<player> normal, vip;
    priority_queue<table> tennis;
    vector<player> left;
    cin >> n;
    for(i = 0; i < n; ++i) {
        int hh, mm, ss, p, t, to_second;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &t);
        to_second = hh * 60 * 60 + mm * 60 + ss;
        p *= 60;
        player tmp{};
        tmp.arrive_time = to_second;
        if(p <= 2 * 60 * 60) tmp.play_time = p;
        else tmp.play_time = 2 * 60 * 60;
        if(t == 0) normal.push(tmp);
        else vip.push(tmp);
    }
    cin >> k >> m;
    vector<int> viptable(m);
     for(i = 0; i < m; ++i) cin >> viptable[i];
    for(i = 1; i <= k; ++i) {
        table tmp{i, 8 * 60 * 60, 0};
        if(find(viptable.begin(), viptable.end(), i) != viptable.end()) tmp.tag = 1;
        tennis.push(tmp);
    }
    while(!vip.empty() || !normal.empty()) {
        table tt = tennis.top(), next;
        tennis.pop();

        player vv{-1}, nn{-1} , occupied;
        if(!vip.empty()) vv = vip.top();
        if(!normal.empty()) nn = normal.top();
        // when it is the turn of a VIP pair, always check if there is a empty vip table.
        //no vip players
        if(vv.arrive_time == -1) {
            occupied = nn;
            normal.pop();
        }
        //no normal players
        else if(nn.arrive_time == -1) {
            tt = find_vip(tennis, tt);
            occupied = vv;
            vip.pop();
        }
        //both in the queue
        else if(vv.arrive_time <= tt.time && nn.arrive_time <= tt.time) {
            tt = find_vip(tennis, tt);
            if(tt.tag == 1) {
                occupied = vv;
                vip.pop();
            }
            else {
                if(vv.arrive_time <= nn.arrive_time) {
                    occupied = vv;
                    vip.pop();
                }
                else {
                    occupied = nn;
                    normal.pop();
                }
            }
        }
        else if(vv.arrive_time <= nn.arrive_time) {
            tt = find_vip(tennis, tt);
            occupied = vv;
            vip.pop();
        }
        else if(vv.arrive_time > nn.arrive_time) {
            occupied = nn;
            normal.pop();
        }
        if(occupied.arrive_time > tt.time) tt.time = occupied.arrive_time;
        occupied.serving_time = tt.time;
        occupied.waiting_time = tt.time - occupied.arrive_time;
        tt.time += occupied.play_time;
        if(occupied.serving_time < 21 * 60 * 60) {
            served[tt.id]++;
            left.emplace_back(occupied);
        }
        tennis.push(tt);
    }
    for(auto l = left.begin(); l != left.end(); ++l) {
        if(l->serving_time < 21 * 60 * 60) {
            int ah, am, as, sh, sm, ss, w;
            ah = l->arrive_time / (60 * 60);
            am = l->arrive_time % (60 * 60) / 60;
            as = l->arrive_time % (60 * 60) % 60;
            sh = l->serving_time / (60 * 60);
            sm = l->serving_time % (60 * 60) / 60;
            ss = l->serving_time % (60 * 60) % 60;
            w = int(round((l->waiting_time * 1.0) / 60.0));
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", ah, am, as, sh, sm, ss, w);
        }
    }
    for(i = 1; i <= k; ++i) printf("%s%d", (i==1?"":" "), served[i]);
    return 0;
}