#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    map<int, int> x;
    cin >> N;
    for(int i = 1; i <= N; ++i) x[i / 2 + i / 3 + i / 5]++;
    cout << x.size();
    return 0;
}