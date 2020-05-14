#include <queue>
#include <iostream>
using namespace std;

struct window {
    int no;
    int minutes;

    // another way
    bool operator< (window b) const {
        if(minutes == b.minutes) return no > b.no;
        return minutes > b.minutes;
    }
};

// Only use operator<. Oterhwise there will be errors.
// It's one of ways to use priority_queue. Never use (window &a, window &b).

// if I want windows to be sorted from small to large by their minutes. And if two or more of them have same minutes,
// they will be sorted from small to large by their no.
//bool operator< (window a, window b) {
//    if(a.minutes == b.minutes) return a.no > b.no;
//    return a.minutes > b.minutes;
//}

int main() {
    priority_queue<window> w;
    w.push({1, 1});
    w.push({2, 2});
    w.push({3, 2});
    w.push({4, 4});
    w.push({5, 1});

    while(!w.empty()) {
        window f = w.top();
        w.pop();
        cout << f.no << ' ' << f.minutes << endl;
    }
}