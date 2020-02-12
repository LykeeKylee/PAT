#include <iostream>
#include <cmath>
typedef unsigned int uint;
using namespace std;

bool judge(int x) {
    bool isSu = true;
    for(uint i = 2; i <= sqrt(x); ++i){
        if(x % i == 0)
            isSu = false;
    }
    return isSu;
}

int main() {
    int lower, upper, cnt = 1, flag = 1;
    cin>>lower>>upper;
    if(lower == 1){
        cout << 2;
        ++flag;
    }
    for(uint i = 3; i <= 10e32; i = i + 2){
        if(judge(i)) {
            ++cnt;
            if(cnt > upper)
                break;
            else if(cnt >= lower && cnt <= upper){
                if(flag == 1)
                    cout << i;
                else if(flag == 10)
                    cout << ' ' << i << endl;
                else
                    cout << ' ' << i;

                ++flag;
                if(flag > 10)
                    flag = 1;
            }
        }
    }
    return 0;
}