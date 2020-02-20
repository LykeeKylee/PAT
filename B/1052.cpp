#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string &x) {
    vector<string> vx;
    int len = x.length();
    for(int i = 0; i < len; ++i) {
        if(x[i] == '[') {
            int j = i + 1;
            while(x[j] != ']')
                j++;
            vx.emplace_back(x.substr(i + 1, j - i - 1));
            i = j;
        }
    }
    return vx;
};

int main() {
    string shands, seyes, smouths;
    getline(cin, shands);
    getline(cin, seyes);
    getline(cin, smouths);
    vector<string> hands = split(shands), eyes = split(seyes), mouths = split(smouths);
    int N, kao[5];
    cin >> N;
    while(N--) {
        bool flag = true;
        for(int i = 0; i < 5; ++i) {
            cin >> kao[i];
            if((kao[i] == 0 || ((i == 0 || i == 4) && kao[i] > hands.size())) || ((i == 1 || i == 3) && kao[i] > eyes.size()) || (i == 2 && kao[i] > mouths.size()))
                flag = false;
        }
        if(!flag)
            cout << "Are you kidding me? @\\/@" << endl;
        else
            cout << hands[kao[0] - 1] << '(' << eyes[kao[1] - 1] << mouths[kao[2] - 1] << eyes[kao[3] - 1] << ')' << hands[kao[4] - 1] << endl;
    }
    return 0;
}