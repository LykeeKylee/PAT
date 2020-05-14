#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int width;
    char signal;
    cin >> width >> signal;
    int half = int(round(width * 0.5)) - 2;
    cout << setw(width) << setfill(signal) << signal << endl;
    for(int i = 0; i < half; ++i) {
        cout << signal << setw(width - 1) << setfill(' ') << signal << endl;
    }
    cout << setw(width) << setfill(signal) << signal << endl;
    return 0;
}