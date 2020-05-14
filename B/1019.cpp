#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    string x, rx, result;
    cin >> x;
    do{
        int fill = 4 - x.length();
        while(fill--) {
            x = '0' + x;
        }
        sort(x.begin(), x.end());
        rx = x;
        reverse(rx.begin(), rx.end());
        result = to_string(atoi(rx.c_str()) - atoi(x.c_str()));
        cout << setw(4) << setfill('0') << rx;
        cout << " - ";
        cout << setw(4) << setfill('0') << x;
        cout << " = ";
        cout << setw(4) << setfill('0') << result << endl;
        x = result;
    } while(x != "6174" && x != "0");
    return 0;
}