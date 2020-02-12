#include <iostream>
using namespace std;

int main() {
    int cnt;
    int n;
    cin >> n;
    cnt = 0;
    while(n != 1){
        n = (n % 2 == 0) ? (n / 2) : ((3 * n + 1) / 2);
        ++cnt;
    }
    cout<<cnt<<endl;
    return 0;
}