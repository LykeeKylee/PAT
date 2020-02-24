#include <iostream>
#include <string>
using namespace std;

bool asc[128] = {false};

int main() {
    string a, b, ret;
    getline(cin, a); getline(cin, b);
    for(char i : a) {
        if(!asc[int(i)]) {
            ret.push_back(i);
            asc[int(i)] = true;
        }
    }
    for(char i : b) {
        if(!asc[int(i)]) {
            ret.push_back(i);
            asc[int(i)] = true;
        }
    }
    printf("%s", ret.c_str());
    return 0;
}