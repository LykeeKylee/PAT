#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string id, head, fresh;
    int N, x, y;
    cin >> N;
    double dst, maxd = -1., mind = -1.;
    while(N--) {
        cin >> id >> x >> y;
        dst = sqrt(x * x + y * y);
        if(maxd == -1) {
            maxd = dst, mind = dst;
            head = id, fresh = id;
        }
        else {
            if(maxd < dst)
                maxd = dst, fresh = id;
            if(mind > dst)
                mind = dst, head = id;
        }
    }
    printf("%s %s", head.c_str(), fresh.c_str());
    return 0;
}