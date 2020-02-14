#include <iostream>
#include <string>
#define SHORT 0
#define CHARERROR 1
#define NONENUM 2
#define NONEALPHA 3
#define PERFECT 4
using namespace std;

int main() {
    int len;
    cin >> len;
//    todo:³Ôµô»Ø³µ
    getchar();
    string pwd;
    int error = 0;
    for(int i = 0; i < len; ++i) {
//        TODO:¿Õ¸ñÏÝÚå
//        cin >>pwd;
        getline(cin, pwd);
        error = PERFECT;
        bool num = false, alpha = false;
        if(pwd.length() >= 6) {
            for(int j = 0; j < pwd.length(); ++j) {
                if(pwd[j] <= '9' && pwd[j] >= '0')
                    num = true;
                else if((pwd[j] <= 'z' && pwd[j] >= 'a') || (pwd[j] <= 'Z' && pwd[j] >= 'A'))
                    alpha = true;
                else if(pwd[j] != '.'){
                    error = CHARERROR;
                    break;
                }
            }
            if(error != CHARERROR) {
                if(num && alpha)
                    error = PERFECT;
                else if(alpha)
                    error = NONENUM;
                else if(num)
                    error = NONEALPHA;
            }
        }
        else
            error = SHORT;

        if(i != 0)
            cout << endl;

        switch (error) {
            case SHORT:
                cout << "Your password is tai duan le.";
                break;
            case CHARERROR:
                cout << "Your password is tai luan le.";
                break;
            case NONENUM:
                cout << "Your password needs shu zi.";
                break;
            case NONEALPHA:
                cout << "Your password needs zi mu.";
                break;
            case PERFECT:
                cout << "Your password is wan mei.";
                break;
            default:
                break;
        }
    }
    return 0;
}