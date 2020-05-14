#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int addone(int a){
    return a + 1;
}

int main() {
    // to_string
    cout << "123: " << to_string(123) << endl;
    cout << "0113: " << to_string(0113) << endl;
    cout << "3.1415: " << to_string(3.1415) << endl << endl;

    // stoi...
    cout << "123: " << stoi("123", nullptr, 10) << endl;
    cout << "0xff: " << stoi("0xff", nullptr, 16) << endl;
    cout << "123ab: " << stoi("123ab", nullptr, 10) << endl << endl;

    // atoi...
    string num = "123";
    cout << "123: " << atoi("123") << endl;
    cout << "num: " << atoi(num.c_str()) << endl << endl;

    // lower upper
    char a = 'A', b = 'b';
    cout << "A to a: " << char(tolower(a)) << endl;
    cout << "b to B: " << char(toupper(b)) << endl;
    string strlower = "abcde1234";
    transform(strlower.begin(), strlower.end(), strlower.begin(), ::toupper);
    cout << "String to Upper£º " << strlower << endl;
    transform(strlower.begin(), strlower.end(), strlower.begin(), ::tolower);
    cout << "String to Lower: " << strlower << endl;

    int n[] = {1, 2, 3, 4, 5};
    transform(n, n + 5, n, addone);
    for(int i = 0; i < 5; ++i) cout << n[i] << ' ';
    return 0;
}