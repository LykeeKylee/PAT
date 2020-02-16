#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, Q;
    int B, left = 0;
    cin >> A >> B;
    for(int i = 0; i < A.length(); ++i) {
        left *= 10;
        left += (A[i] - '0');
        if(left >= B) {
            Q += char(left / B + '0');
            left %= B;
        }
        else {
            if(i != 0) {
                Q += '0';
                left = (A[i] - '0');
            }
        }
    }
    if(Q.length() >= 1)
        cout << Q << ' ' << left;
    else
        cout << '0' << ' ' << left;
    return 0;
}