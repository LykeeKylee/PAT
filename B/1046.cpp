#include <iostream>
using namespace std;

int main() {
    int round, array[4], cntA = 0, cntB = 0, sum = 0;
    cin >> round;
    for(int i = 0; i < round; ++i) {
        for(int j = 0; j < 4; ++j) {
            cin >> array[j];
        }
        sum = array[0] + array[2];
        if(sum == array[1] && sum != array[3])
            ++cntB;
        else if(sum != array[1] && sum == array[3])
            ++cntA;
    }
    cout << cntA << ' ' << cntB;
    return 0;
}