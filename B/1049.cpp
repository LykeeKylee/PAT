#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    double x, sum = 0.0;
    for(int i = 0; i < N; ++i) {
        scanf("%lf", &x);
        sum += (x * (i + 1) * (N - i));
    }
    printf("%.2lf", sum);
    return 0;
}