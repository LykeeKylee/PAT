#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int troops[1001], troop, player, grade, N, maxT = -1, maxG = -1;
    memset(troops, 0, sizeof(troops));
    cin >> N;
    while(N--) {
        scanf("%d-%d %d", &troop, &player, &grade);
        troops[troop - 1] += grade;
        if(troops[troop - 1] > maxG) {
            maxG = troops[troop - 1];
            maxT = troop;
        }
    }
    cout << maxT << ' ' << maxG;
    return 0;
}