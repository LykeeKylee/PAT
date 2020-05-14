#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool legal(string &x, double &num) {
    int dot = 0, xiaoshu = 0;
    bool islegal = true;
    for(int i = 0; i < x.length(); ++i) {
        if(x[i] == '.') {
            ++dot;
            if(dot > 1) {
                islegal = false;
                break;
            }
        }
        else if(x[i] <= '9' && x[i] >= '0') {
            if(dot > 0)
                ++xiaoshu;
            if(xiaoshu > 2) {
                islegal = false;
                break;
            }
        }
        else if(i == 0 && (x[i] == '+' || x[i] == '-')) {
            continue;
        }
        else {
            islegal = false;
            break;
        }
    }
    if(islegal) {
        num = atof(x.c_str());
        if(num > 1000.0 || num < -1000.0)
            islegal = false;
    }
    return islegal;
}

int main() {
    int N, ncnt = 0;
    string x, one;
    double cnt = 0.0;
    char *_char;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> x;
        double num;
        if(!legal(x, num))
            cout << "ERROR: " << x << " is not a legal number" << endl;
        else {
            ++ncnt;
            cnt += num;
            one = x;
        }
    }
    if(ncnt == 0)
        cout << "The average of 0 numbers is Undefined" << endl;
    else if(ncnt == 1)
        cout << setiosflags(ios::fixed) << setprecision(2) << "The average of " << ncnt << " number is " << cnt / ncnt <<endl;
    else
        cout << setiosflags(ios::fixed) << setprecision(2) << "The average of " << ncnt << " numbers is " << cnt / ncnt <<endl;
    return 0;
}