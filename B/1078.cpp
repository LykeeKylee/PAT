#include <iostream>
#include <string>
using namespace std;

int main() {
    char fun;
    string str;
    int i = 0;
    cin >> fun;getchar();
    getline(cin, str);
    switch (fun) {
        case 'C': {
            while(i < str.length()) {
                int start = i++;
                while(i < str.length() && str[i] == str[start]) ++i;
                if(i - start == 1)  cout << str[start];
                else cout << i - start << str[start];
            }
            break;
        }
        case 'D': {
            while(i < str.length()) {
                if(str[i] >= '0' && str[i] <= '9') {
                    int pos = i++, x;
                    while(i < str.length() && str[i] >= '0' && str[i] <= '9') ++i;
                    x = atoi(str.substr(pos, i - pos).c_str());
                    while(x--) cout << str[i];
                    ++i;
                }
                else cout << str[i++];
            }
            break;
        }
    }
    return 0;
}