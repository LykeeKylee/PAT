#include <bits/stdc++.h>
using namespace std;

struct s {
    int id;
    int g[4];
    int r[4];
};

bool exist[1000007];
char c[4] = {'A', 'C', 'M', 'E'};

bool cmpa(s &a, s &b) { return a.g[0] > b.g[0];}
bool cmpc(s &a, s &b) { return a.g[1] > b.g[1];}
bool cmpm(s &a, s &b) { return a.g[2] > b.g[2];}
bool cmpe(s &a, s &b) { return a.g[3] > b.g[3];}

int main() {
    int n, m, i, j;
    cin >> n >> m;
    vector<s> allover;
    fill(exist, exist + 1000007, false);
    for(i = 0; i < n; ++i) {
        s temp{};
        cin >> temp.id >> temp.g[1] >> temp.g[2] >> temp.g[3];
        temp.g[0] = int(round((temp.g[1] + temp.g[2] + temp.g[3]) / 3.0));
        exist[temp.id] = true;
        allover.emplace_back(temp);
    }
    for(i = 0; i < 4; ++i) {
        switch (i) {
            case 0: { sort(allover.begin(), allover.end(), cmpa); break;}
            case 1: { sort(allover.begin(), allover.end(), cmpc); break;}
            case 2: { sort(allover.begin(), allover.end(), cmpm); break;}
            case 3: { sort(allover.begin(), allover.end(), cmpe); break;}
            default: break;
        }
        int size = allover.size(), rank = 0, grade = -1, offset = 1;
        for(j = 0; j < size; ++j) {
            if(allover[j].g[i] != grade) {
                allover[j].r[i] = rank + offset;
                rank += offset;
                offset = 1;
            }
            else {
                allover[j].r[i] = rank;
                offset++;
            }
            grade = allover[j].g[i];
        }
    }

    int id, size = allover.size();
    for(i = 0; i < m; ++i) {
        cin >> id;
        if(exist[id]) {
            for(j = 0; j < size; ++j){
                if(allover[j].id == id) break;
            }
            int *p = min_element(allover[j].r, allover[j].r + 4);
            cout << *p << ' ' << c[p - allover[j].r] << endl;
        }
        else
            cout << "N/A" << endl;
    }
    return 0;
}