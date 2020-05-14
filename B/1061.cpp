#include <iostream>
using namespace std;

int main() {
    int stu, problem;
    cin >> stu >> problem;
    int *point = new int[problem], *rightA = new int[problem];
    for(int i = 0; i < problem; ++i) {
        cin >> point[i];
    }
    for(int i = 0; i < problem; ++i) {
        cin >> rightA[i];
    }
    int *answer = new int[problem], sum;
    for(int i = 0; i < stu; ++i) {
        sum = 0;
        for(int j = 0; j < problem; ++j) {
            cin >> answer[j];
            if(answer[j] == rightA[j])
                sum += point[j];
        }
        cout << sum << endl;
    }
    delete[]point;
    delete[]rightA;
    delete[]answer;
    return 0;
}