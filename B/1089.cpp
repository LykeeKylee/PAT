#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, flag = 0;
    cin >> n;
    vector<int> player(n + 1);
    for(int i = 1; i <= n; ++i) cin >> player[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            vector<int> lier, ret(n + 1, 1);
            ret[i] = ret[j] = -1;
            for(int k = 1; k <= n; ++k) {
                if(player[k] * ret[abs(player[k])] < 0)
                    lier.emplace_back(k);
            }
            if(lier.size() == 2 && ret[lier[0]] + ret[lier[1]] == 0){
                flag = 1;
                cout << i << ' ' << j;
                break;
            }
        }
        if(flag == 1)
            break;
    }
    if(flag != 1)
        cout << "No Solution";
    return 0;
}