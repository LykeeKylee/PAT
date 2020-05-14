#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string text[4];
    for(int i = 0; i < 4; ++i)
        cin >> text[i];
    string weekday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int len = text[0].length() < text[1].length() ? text[0].length() : text[1].length();
    int flag = 0;
    for(int i = 0; i < len; ++i) {
        if(text[0][i] == text[1][i]) {
            if(text[0][i] >= 'A' && text[0][i] <= 'Z') {
                if(flag == 0 && text[0][i] <= 'G') {
                    cout << weekday[int(text[0][i]) - 'A'] << ' ';
                    ++flag;
                }
                else if(flag == 1 && text[0][i] <= 'N') {
                    cout << setw(2) << 10 + int(text[0][i] - 'A') << ':';
                    ++flag;
                }
            }
            else if (text[0][i] >= '0' && text[0][i] <= '9') {
                if(flag == 1){
                    cout << setw(2) << setfill('0') << text[0][i] << ':';
                    ++flag;
                }
            }
        }
        if(flag >= 2)
            break;
    }
    len = text[2].length() < text[3].length() ? text[2].length() : text[3].length();
    for(int i = 0; i < len; ++i) {
        if(text[2][i] == text[3][i] && ((text[2][i] >= 'a' && text[2][i] <= 'z') || (text[2][i] >= 'A' && text[2][i] <= 'Z'))){
                cout << setw(2) << setfill('0') << i;
                break;
        }
    }
    return 0;
}