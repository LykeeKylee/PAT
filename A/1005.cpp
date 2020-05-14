#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    long long int cnt = 0;
    string digit[10] = {"zero", "one", "two", "three", "four", "five", "six",
                        "seven", "eight", "nine"};
    getline(cin, num);
    for(int i = 0; i < num.size(); ++i) {
        cnt += (num[i] - '0');
    }
    num = to_string(cnt);
    for(int i = 0; i < num.size(); ++i) {
        printf("%s%s", (i == 0 ? "" : " "), digit[num[i] - '0'].c_str());
    }
    return 0;
}