#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;
    int num, kn;
    for(int i = 0; i < m; ++i) {
        cin >> num;
        bool flag = false;
        for(int n = 1; n < 10; ++n) {
            kn = num * num * n;
            int pre = 10;
            while(num / pre != 0)
                pre *= 10;
            if(kn % pre == num){
                cout << n << ' ' << kn << endl;
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "No" << endl;
    }
    return 0;
}