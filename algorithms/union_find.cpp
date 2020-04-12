#include <iostream>
#include <vector>
#include <string>

using namespace std;

void init(int Union[], int n) {
    for(int i = 0; i < n; ++i) Union[i] = i;
}

int findSrc(int x, int Union[]) {
    int src = x;
    while(src != Union[src]) src = Union[src];
    while(x != Union[x]) {
        int tmp = x;
        x = Union[x];
        Union[tmp] = src;
    }
    return src;
}

void join(int x, int y, int Union[]) {
    int xSrc = findSrc(x, Union), ySrc = findSrc(y, Union);
    if(xSrc != ySrc) Union[ySrc] = Union[xSrc];
}

string ret(bool x) {
    return x ? "Yes" : "No";
}

bool judge(int x, int y, int Union[]) {
    int xSrc = findSrc(x, Union), ySrc = findSrc(y, Union);
    return xSrc == ySrc;
}

int main() {
    int Union[100], a[3] = {1, 2, 3}, b[3] = {3, 4, 5}, c[4] = {6, 7, 8}, d[2] = {9, 10}, i, src;
    init(Union, 100);
    src = a[0];
    for(i = 1; i < 3; ++i) join(src, a[i], Union);
    src = b[0];
    for(i = 1; i < 3; ++i) join(src, b[i], Union);
    src = c[0];
    for(i = 1; i < 4; ++i) join(src, c[i], Union);
    src = d[0];
    for(i = 1; i < 2; ++i) join(src, d[i], Union);

    cout << "1 and 3: " << ret(judge(1, 3, Union)) << endl;
    cout << "1 and 4: " << ret(judge(1, 4, Union)) << endl;
    cout << "1 and 10: " << ret(judge(1, 10, Union)) << endl;
    return 0;
}