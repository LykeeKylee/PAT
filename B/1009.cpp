#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
//    getline(cin, str);
    stack<string> strstack;
    do {
        cin >> str;
        strstack.push(str);
    }while(getchar() != '\n');
    bool flag = true;
    while(!strstack.empty()) {
        if(flag) {
            cout << strstack.top();
            flag = false;
        }
        else {
            cout << ' ' << strstack.top();
        }
        strstack.pop();
    }
    return 0;
}