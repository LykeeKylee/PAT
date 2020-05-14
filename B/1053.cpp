#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N, D, K, maykong = 0, kong = 0, N_;
    double e, *E;
    cin >> N >> e >> D;
    N_ = N;
    while(N_--) {
        cin >> K;
        E = new double[K];
        int cnt = 0;
        for(int i = 0; i < K; ++i) {
            cin >> E[i];
            if(E[i] < e)
                ++cnt;
        }
        if(cnt > (K / 2.0)) {
            if(K > D)
                ++kong;
            else
                ++maykong;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(1) << (maykong * 100.0 / N) << "% " << (kong * 100.0 / N) << '%' <<endl;
}