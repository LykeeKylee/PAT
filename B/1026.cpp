#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int C1, C2, gap;
    cin >> C1 >> C2;
    gap = int(round((C2 - C1) / 100.0));
//    TODO:注意输出格式
    cout << setw(2) << setfill('0') << gap / 3600;
    cout << ':';
    cout << setw(2) << setfill('0') << (gap % 3600) / 60;
    cout << ':';
    cout << setw(2) << setfill('0') << gap % 3600 % 60;
//    printf("%2d:%2d:%2d", gap / 3600, (gap % 3600) / 60, gap % 3600 % 60);
    return 0;
}