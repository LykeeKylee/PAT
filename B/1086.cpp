#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string answer = to_string(a * b);
    while(answer.length() > 0 && answer.back() == '0')
        answer.pop_back();
    reverse(answer.begin(), answer.end());
    cout << answer;
    return 0;
}