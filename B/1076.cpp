#include <iostream>
#include <string>
using namespace std;

int main() {
    int length;
    cin >> length;
    string key;
    string pwd;
    for(int i = 0; i < length; ++i) {
        for(int j = 0; j < 4; ++j) {
            cin >> key;
            if(key[2] == 'T')
                pwd.push_back(char(key[0] - 'A' + '1'));
        }
    }
    cout << pwd;
    return 0;
}