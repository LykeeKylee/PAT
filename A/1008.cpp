#include <bits/stdc++.h>
using namespace std;

const int up = 6, down = 4, stop = 5;

int main() {
     int n, curfloor = 0, time = 0;
     cin >> n;
     vector<int> req(n);
     for(int i = 0; i < n; ++i) {
         int floor;
         cin >> floor;
         if(curfloor == floor) time += stop;
         else if(curfloor > floor) time += (stop + (curfloor - floor) * down);
         else time += (stop + (floor - curfloor) * up);
         curfloor = floor;
     }
     cout << time;
     return 0;
}