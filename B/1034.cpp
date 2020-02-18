#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void split(string &ab, int &a, int &b) {
    int pos = ab.find('/'), len = ab.length();
    if(ab[0] == '-') {
        a = -1 * atoi(ab.substr(1, pos - 1).c_str());
    }
    else {
        a = atoi(ab.substr(0, pos).c_str());
    }
    b = atoi(ab.substr(pos + 1, len - pos - 1).c_str());
}

int findMax(int a, int b) {
    int _min = a < b ? a : b, i, _max = 1;
    for(i = _min; i >= 1; --i) {
        if(a % i == 0 && b % i == 0 && i > _max) {
            _max = i;
            break;
        }
    }
    return _max;
}

string simplify(int a, int b) {
    string sim;
    int sign = a < 0 ? -1 : 1;
    a = abs(a);
    if(a == 0) {
        sim = "0";
    }
    else {
        int _max = findMax(a, b);
        a /= _max;
        b /= _max;

        if(a / b == 0) {
            sim = to_string(a) + '/' + to_string(b);
        }
        else {
            if(a % b != 0)
                sim = to_string(a / b) + ' ' + to_string(a % b) + '/' + to_string(b);
            else
                sim = to_string(a / b);
        }
    }
    if(sign == -1)
        sim = "(-" + sim + ')';
    return sim;
}

int main() {
    int a1, b1, a2, b2, plus[2], minus[2], mul[2], div[2];
    string ab1, ab2;
    bool isInf = false;
    cin >> ab1 >> ab2;

    split(ab1, a1, b1);
    split(ab2, a2, b2);

    plus[0] = a1 * b2 + a2 * b1;
    plus[1] = b1 * b2;
    minus[0] = a1 * b2 - a2 * b1;
    minus[1] = plus[1];
    mul[0] = a1 * a2;
    mul[1] = b1 * b2;
    if(a2 == 0)
        isInf = true;
    else {
        div[0] = abs(a1) * b2;
        div[1] = b1 * abs(a2);
        div[0] = a1 * a2 < 0 ? -div[0] : div[0];
    }

    ab1 = simplify(a1, b1);
    ab2 = simplify(a2, b2);
    cout << ab1 << " + " << ab2 << " = " << simplify(plus[0], plus[1]) << endl;
    cout << ab1 << " - " << ab2 << " = " << simplify(minus[0], minus[1]) << endl;
    cout << ab1 << " * " << ab2 << " = " << simplify(mul[0], mul[1]) << endl;
    cout << ab1 << " / " << ab2 << " = ";
    if(isInf)
        cout << "Inf";
    else
        cout << simplify(div[0], div[1]);
    return 0;
}