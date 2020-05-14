#include <iostream>
#include <string>
using namespace std;

struct testId {
    string id;
    int lid;
};

int main() {
    int student;
    cin >> student;
    testId seq[1000];
    string a;
    int b, c;
    for(int i = 0; i < student; ++i) {
        cin >> a >> b >> c;
        seq[b - 1].id = a;
        seq[b - 1].lid = c;
    }
    int requst;
    cin >> requst;
    for(int i = 0; i < requst; ++i) {
        int req;
        cin >> req;
        cout << seq[req - 1].id << ' ' << seq[req - 1].lid << endl;
    }
    return 0;
}