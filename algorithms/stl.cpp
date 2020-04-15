#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

// 1: sort a set with my rule
struct setcmp {
    bool operator() (const int &a, const int &b) const {
        return a > b;
    }
//    set<type, setcmp> set1;
};

// 2: sort a set with my rule
struct t {
    int a;
    int b;
    bool operator< (const t &y) const {
        return this->a < y.a;
    }
//    set<type> set2;
};

int main() {
    int a[6] = {2, 1, 1, 3, 5, 4};

    //vector
    cout << endl << "Vector" << endl;
    vector<int> v(a, a + 6);
    v.emplace_back(10);
    v.push_back(11);
    v.insert(v.end(), 10, 9);
    v.emplace(v.end(), 12);
    cout << v.back() << endl;
    v.pop_back();
    cout << v.back() << endl;

    //set
    cout << endl << "Set" << endl;
    set<int> set1(a, a + 6);
    set<int, setcmp> set2(a, a + 6);
    set1.insert(9);
    cout << set1.size() << ' ' << set2.size() << endl;
    for(auto i = set1.begin(); i != set1.end(); ++i) cout << *i << ' ';
    cout << endl;
    for(auto i = set2.begin(); i != set2.end(); ++i) cout << *i << ' ';
    cout << endl;
//    cout << *set1.lower_bound(0) << endl;
//    cout << *set1.upper_bound(4) << endl;

    // map
    cout << endl << "Map" << endl;
    map<int, int> m1;
    unordered_map<int, int> m2;
    for(int i = 0; i < 6; ++i) m1[i] = m2[i] = a[i];
    for(auto m = m1.begin(); m != m1.end(); ++m) cout << m->first << ":" << m->second << ' ';
    cout << endl;
    for(auto m = m2.begin(); m != m2.end(); ++m) cout << m->first << ":" << m->second << ' ';

    //pair
    cout << endl << "Pair" << endl;
    pair<int, string> p1(1, "123");
    pair<int, string> p2 = make_pair(1, "123");
    int pn;
    string ps;
    tie(pn, ps) = p1;
    cout << p1.first << ' ' << p1.second << endl;
    cout << pn << ' ' << ps << endl;
}