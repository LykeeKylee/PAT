#include <iostream>
using namespace std;

int main() {
    int N, N_;
    char sign;
    cin >> N >> sign;
    --N;
    N_ = N;
    int floor = 1;
    while(N_ >= 0) {
        floor += 2;
        N_ -= (2 * floor);
    }
    N_ += (2 * floor);
    floor -= 2;
    for(int i = floor; i >= 1; i = i - 2) {
        int blank = (floor - i) / 2;
        for(int j = 0; j < blank; ++j)
            cout << ' ';

        for(int j = 0; j < i; ++j)
            cout << sign;
        cout << endl;
    }
    for(int i = 3; i <= floor; i = i + 2) {
        int blank = (floor - i) / 2;
        for(int j = 0; j < blank; ++j)
            cout << ' ';

        for(int j = 0; j < i; ++j)
            cout << sign;
        cout << endl;
    }
    cout << N_;
    return 0;
}