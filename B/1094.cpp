#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool check(long long x) {
    if(x == 2)
        return true;
    else if(x == 0 || x == 1 || x % 2 == 0)
        return  false;
    else {
        for(long long i = 3; i <= (long long)(sqrt(x)); i += 2) {
            if(x % i == 0)
                return false;
        }
    }
    return true;
}

int main() {
    int l, k;
    scanf("%d %d", &l, &k);
    getchar();
    string num;
    getline(cin, num);
    if(l < k)
        printf("%d", 404);
    else {
        long long n = 0;
        bool flag = false;
        string ret;
        for(int i = 0; i < l; ++i) {
            if(i + k <= l) {
                n = 0;
                ret.clear();
                for(int j = i; j < i + k; ++j) {
                    n *= 10;
                    n += (num[j] - '0');
                    ret += num[j];
                }
                if(check(n)) {
                    flag = true;
                    break;
                }
            }
            else break;
        }
        if(flag)
            printf("%s", ret.c_str());
        else
            printf("%d", 404);
    }
    return 0;
}