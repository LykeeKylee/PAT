#include <iostream>
#include <string>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main() {
    string sci, number, index;
    cin >> sci;
    char sign[2];
    ull dot = 1, index_;
    ll zero;
    bool isIndex = false;
    for(ull i = 0; i < sci.length(); ++i) {
        if(sci[i] == '+' || sci[i] == '-') {
            if(i == 0)
                sign[0] = sci[i];
            else
                sign[1] = sci[i];
        }
        else if(sci[i] == '.') {
            dot = i - 1;
        }
        else if(sci[i] == 'E')
            isIndex = true;
        else {
            if(!isIndex)
                number += sci[i];
            else
                index += sci[i];
        }
    }

    if(sign[0] == '-')
        cout << sign[0];
    index_ = atoi(index.c_str());
    if(sign[1] == '+') {

        zero = index_ - number.length() + 1;
        if(zero >= 0) {
            cout << number;
            while(zero--)
                cout << '0';
        }
        else {
            index_ += dot;
            for(ull i = 0; i < number.length(); ++i) {
                if(i == index_)
                    cout << '.';
                cout << number[i];
            }
        }
    }
    else {
        cout << "0.";
        zero = index_ - 1;
        while(zero--) {
            cout << '0';
        }
        cout << number;
    }
    return 0;
}