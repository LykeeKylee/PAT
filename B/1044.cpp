#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string low[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
       high[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main() {
    int N;
    cin >> N;
    getchar();
    string str;
    while(N--) {
        getline(cin, str);
        if(str.length() > 0) {
            if(str[0] >= '0' && str[0] <= '9') {
                int num = atoi(str.c_str());
                if(num < 13)
                    cout << low[num] << endl;
                else if(num % 13 == 0)
                    cout << high[num / 13 - 1] << endl;
                else
                    cout << high[num / 13 - 1] << ' ' << low[num % 13] << endl;
            }
            else {
                int pos = str.find(' '), num = 0;
                if(pos == string::npos) {
                    for(int i = 0; i < 12; ++i) {
                        if(high[i] == str) {
                            num += (13 * (i + 1));
                            break;
                        }
                    }
                    for(int i = 0; i < 13; ++i) {
                        if(low[i] == str) {
                            num += i;
                            break;
                        }
                    }
                }
                else {
                    string str1 = str.substr(0, pos), str2 = str.substr(pos + 1, str.length() - pos - 1);
                    for(int i = 0; i < 12; ++i) {
                        if(high[i] == str1) {
                            num += (13 * (i + 1));
                            break;
                        }
                    }
                    for(int i = 0; i < 13; ++i) {
                        if(low[i] == str2) {
                            num += i;
                            break;
                        }
                    }
                }
                cout << num << endl;
            }
        }
    }
    return 0;
}