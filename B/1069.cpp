#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int zongliang, jiange, first, i, next;
    cin >> zongliang >> jiange >> first;
    getchar();
    next = first;
    map<string, int> mingdan;
    string t;
    if(first > zongliang) {
        cout << "Keep going...";
    }
    else {
        for(i = 0; i < zongliang; ++i) {
            getline(cin, t);
            if(i + 1 == next) {
                if(mingdan[t] != 1) {
                    cout << t << endl;
                    mingdan[t] = 1;
                    next += jiange;
                }
                else {
                    ++next;
                }
            }
        }
    }
    return 0;
}