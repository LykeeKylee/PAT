#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int grades[101], N, K, K_, grade;
    memset(grades, 0, sizeof(grades));
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &grade);
        ++grades[grade];
    }
    scanf("%d", &K);
    K_ = K;
    while(K--) {
        scanf("%d", &grade);
        if(K != K_ - 1)
            printf(" %d", grades[grade]);
        else
            printf("%d", grades[grade]);
    }
    return 0;
}