#include <bits/stdc++.h>
using namespace std;

int main() {
    double peilv = 0.65;
    char pos[3] = {'W', 'T', 'L'};
    for(int i = 0; i < 3; ++i) {
        double x[3];
        for(int j = 0; j < 3; ++j) cin >> x[j];
        double *p = max_element(x, x+3);
        peilv *= *p;
        printf("%s%c", (i == 0 ? "": " "), pos[p - x]);
    }
    peilv--;
    printf(" %0.2lf", peilv * 2);
    return 0;
}