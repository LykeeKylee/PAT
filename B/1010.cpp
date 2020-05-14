#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct exp {
    int a;
    int b;
};

int main() {
    vector<exp> poly;
    int x, y;
    do {
        cin >> x >> y;
        exp temp = {x , y};
        poly.emplace_back(temp);
    } while(getchar() != '\n');

//    todo:系数为0或者指数为0
    if(poly.size() == 1 && (poly[0].a == 0 || poly[0].b == 0))
        cout << "0 0";
    else {
        for(int i = 0; i < poly.size(); ++i) {
            if(poly[i].b != 0 && poly[i].a != 0) {
                if(i != 0)
                    cout << ' ';
                cout << poly[i].a * poly[i].b << ' ' << poly[i].b - 1;
            }
        }
    }
    return 0;
}