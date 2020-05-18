#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int a) {
    if(a == 0 || a == 1) return false;
    else if(a == 2) return true;
    else if(a % 2 == 0) return false;
    int upper = int(sqrt(a));
    for(int i = 3; i <= upper; i += 2) {
        if(a % i == 0) return false;
    }
    return true;
}

int main() {
    for(int i = 0; i <= 1000; ++i) {
        printf("%d: %s\n", i, is_prime(i) ? "true" : "false");
    }
    return 0;
}