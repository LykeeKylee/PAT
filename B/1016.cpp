#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    char DA, DB;
    cin >> A >> DA >> B >> DB;
    int64_t PA = 0, PB = 0;
    int flag = 1;
    for(int i = 0; i < A.length(); ++i) {
        if(A[i] == DA){
            PA += ((DA - '0') * flag);
            flag *= 10;
        }
    }
    flag = 1;
    for(int i = 0; i < B.length(); ++i) {
        if(B[i] == DB){
            PB += ((DB - '0') * flag);
            flag *= 10;
        }
    }
    cout<<PA + PB;
    return 0;
}