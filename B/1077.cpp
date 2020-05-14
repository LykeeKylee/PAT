#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, upper, i, j;
    cin >> N >> upper;
    i = N;
    while(i--) {
        int grade, cnt = 0, final_grade = 0, teacher, max = 0, min = 1000;
        cin >> teacher;
        j = N - 1;
        while(j--) {
            cin >> grade;
            if(grade <= upper && grade >= 0) {
                final_grade += grade;
                cnt++;
                max = max > grade ? max : grade;
                min = min < grade ? min : grade;
            }
        }
        final_grade -= (max + min);
        cnt -= 2;
        cout << round(final_grade * 1.0 / cnt / 2 + teacher * 1.0 / 2) << endl;
    }
    return 0;
}