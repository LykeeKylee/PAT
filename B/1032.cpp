#include <iostream>
#include <cstring>
#define max_size 100002
using namespace std;

int main() {
    int N, grades[max_size], maxSchool = -1, maxGrade = -1, name, grade;
    cin >> N;
    memset(grades, 0, sizeof(grades));
    while(N--) {
        cin >> name >> grade;
        grades[name - 1] += grade;
        if(maxGrade < grades[name - 1]) {
            maxGrade = grades[name - 1], maxSchool = name;
        }
    }
    cout << maxSchool << ' ' << maxGrade;
    return 0;
}