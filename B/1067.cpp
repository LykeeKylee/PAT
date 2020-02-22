#include <iostream>
#include <string>
using namespace std;

int main() {
    string rightPwd, inputPwd;
    int N, cnt = 1;
    cin >> rightPwd >> N;
    getchar();
    while(getline(cin, inputPwd), inputPwd != "#") {
        if(cnt < N) {
            if(inputPwd == rightPwd) {
                cout << "Welcome in" << endl;
                break;
            }
            else {
                cout << "Wrong password: " << inputPwd << endl;
                ++cnt;
            }
        }
        else {
            if(inputPwd == rightPwd) {
                cout << "Welcome in" << endl;
                break;
            }
            else {
                cout << "Wrong password: " << inputPwd << endl;
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}