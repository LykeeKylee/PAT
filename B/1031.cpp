#include <iostream>
#include <string>
using namespace std;

bool check(string &id, const int weight[], const char M[]) {
    int sum = 0;
    bool right = true;
    for(int i = 0; i < 17; ++i) {
        if(id[i] >= '0' && id[i] <= '9') {
            sum += (weight[i] * (id[i] - '0'));
        }
        else {
            right = false;
            break;
        }
    }
    if(right) {
        right = (M[sum % 11] == id[17]);
    }
    return right;
}

int main() {
    int num;
    cin >> num;
    char ArrayM[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    bool passed = true;
    string id;
    for(int i = 0; i < num; ++i){
        cin >> id;
        if(!check(id, weight, ArrayM)) {
            passed = false;
            cout << id << endl;
        }
    }
    if(passed)
        cout << "All passed";
}