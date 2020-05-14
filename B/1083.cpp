#include <iostream>
using namespace std;

int main() {
    int N, *seq, bit[10002] = {0};
    cin >> N;
    seq = new int[N];
    for(int i = 0; i < N; ++i) {
        cin >> seq[i];
        ++bit[abs(seq[i] - i - 1)];
    }
    for(int i = 10001; i >= 0; --i) {
        if(bit[i] != 0 && bit[i] != 1)
            printf("%d %d\n", i, bit[i]);
    }
    return 0;
}