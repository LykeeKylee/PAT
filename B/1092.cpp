#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int *mooncake = new int[N], max = -1;
    memset(mooncake, 0, N * 4);
    while(M--) {
        int x;
        for(int i = 0; i < N; ++i) {
            cin >> x;
            mooncake[i] += x;
            max = mooncake[i] > max ? mooncake[i] : max;
        }
    }
    cout << max << endl;
    bool f = true;
    for(int i = 0; i < N; ++i) {
        if(mooncake[i] == max) {
            if(!f)
                cout << ' ';
            cout << i + 1;
            f = false;
        }
    }
    delete[]mooncake;
    return 0;
}