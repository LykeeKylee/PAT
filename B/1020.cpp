#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct price {
    int no;
    double p;
};

bool cmp(price &x, price &y) {
    return x.p > y.p;
}

int main() {
    int n, d, i;
    cin >> n >> d;
    vector<double> mooncake(n), weight(n);
    vector<price> prices(n);
    for(i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for(i = 0; i < n; ++i) {
        cin >> mooncake[i];
        prices[i].no = i;
        prices[i].p = mooncake[i] * 1.0 / weight[i];
    }
    sort(prices.begin(), prices.end(), cmp);
    double money = 0;
    for(i = 0; i < n && d > 0; ++i) {
        int no = prices[i].no;
        if(d >= weight[no]) {
            d -= weight[no];
            money += mooncake[no];
        }
        else {
            money += (d * prices[i].p);
            d = 0;
        }
    }
    printf("%0.2lf", money);
    return 0;
}