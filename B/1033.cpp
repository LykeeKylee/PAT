#include <iostream>
#include <string>
using namespace std;

int main() {
    string error, input, output;
    getline(cin, error);
    getline(cin, input);
    for(int i = 0; i < input.length(); ++i) {
        if(error.find(input[i]) == string::npos && error.find(toupper(input[i])) == string::npos && !(error.find('+') != string::npos && input[i] <= 'Z' && input[i] >= 'A'))
            output += input[i];
    }
    cout << output;
    return 0;
}