#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int stuNum, wpNum, swpNum, i = 0, stuCnt = 0, wpCnt = 0;
    cin >> stuNum >> wpNum;
    string name, swp;
    map<string, int> wupin;
    for(i = 0; i < wpNum; ++i) {
        cin >> swp;
        ++wupin[swp];
    }
    for(i = 0; i < stuNum; ++i) {
        cin >> name >> swpNum;
        bool bad = false;
        for(int j = 0; j < swpNum; ++j) {
            cin >> swp;
            if(wupin[swp] == 1) {
                ++wpCnt;
                if(!bad)
                    cout << name << ':';
                cout << ' ' << swp;
                bad = true;
            }
        }
        if(bad) {
            cout << endl;
            ++stuCnt;
        }
    }
    cout << stuCnt << ' ' << wpCnt;
    return 0;
}