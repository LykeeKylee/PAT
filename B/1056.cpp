#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int *num = new int[N];
    for(int i = 0; i < N; ++i) {
        cin >> num[i];
    }
    int sum = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(num[i] == num[j])
                continue;
            else {
                sum += (num[i] * 10 + num[j]);
            }
        }
    }
    cout << sum;
    return 0;
}