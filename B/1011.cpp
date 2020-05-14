#include <iostream>
using namespace std;
typedef long long int lli;

//TODO:注意长整型
int main() {
    int num;
    cin >> num;
    lli a, b, c;
    for(int i = 0; i < num; ++i){
        cin >> a >> b >> c;
        if(i == 0)
            printf("Case #%d: %s", i + 1, (a + b > c ? "true" : "false"));
        else
            printf("\nCase #%d: %s", i + 1, (a + b > c ? "true" : "false"));
    }
    return 0;
}