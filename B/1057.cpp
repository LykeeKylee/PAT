#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    int add = 0, zcnt = 0, ocnt = 0;
    for(int i = 0; i < str.length(); ++i) {
        if(tolower(str[i]) <= 'z' && tolower(str[i]) >= 'a')
            add += (tolower(str[i]) - 'a' + 1);
    }
    while(add != 0) {
        if(add % 2 == 0)
            ++zcnt;
        else
            ++ocnt;
        add /= 2;
    }

    cout << zcnt << ' ' << ocnt;
    return 0;
}