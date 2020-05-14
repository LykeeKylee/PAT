#include <iostream>
using namespace std;

void get_rank(int grade[], int rank[], int size) {
    int i, r = 0, g = grade[0] - 1, offset = 1;
    for(i = 0; i < size; ++i) {
        if(grade[i] != g) {
            rank[i] = r + offset;
            r = rank[i];
            offset = 1;
        }
        else {
            rank[i] = r;
            offset++;
        }
        g = grade[i];
    }
}

int main() {
    int grade[6] = {90, 90, 85, 84, 84, 80}, rank[6];
    get_rank(grade, rank, 6);
    for(int i = 0; i < 6; ++i) cout << rank[i] << ' ';
    return 0;
}