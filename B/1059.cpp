#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

struct player {
    string id;
    string award;
    bool isCheck;
};

bool sushu(int x) {
    bool ret = true;
    if(x != 2) {
        for(int i = 2; i <= sqrt(x); ++i) {
            if(x % i == 0) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

string award(int rankNum) {
    string a;
    if(rankNum == 1)
        a = "Mystery Award";
    else if(sushu(rankNum)) {
        a = "Minion";
    }
    else
        a = "Chocolate";
    return a;
}

int main() {
    int N, K, j;
    player *hash[10002];
    for(int i = 0; i < 10002; ++i)
        hash[i] = nullptr;

    cin >> N;
    getchar();
    player *rank = new player[N];
    j = N;
    while(j--) {
        string t;
        getline(cin, t);
        rank[N - j - 1].id = t;
        rank[N - j - 1].award = award(N - j);
        rank[N - j - 1].isCheck = false;
        hash[atoi(t.c_str())] = &rank[N - j - 1];
    }

    cin >> K;
    getchar();
    while(K--) {
        string t;
        getline(cin, t);
        printf("%s: ", t.c_str());
        int xx = atoi(t.c_str());
        if(xx > 9999 || xx < 0) {
            printf("%s\n", "Are you kidding?");
        }
        else {
            player *pos = hash[xx];
            if(pos) {
                if(pos->isCheck)
                    printf("%s\n", "Checked");
                else {
                    printf("%s\n", pos->award.c_str());
                    pos->isCheck = true;
                }
            }
            else
                printf("%s\n", "Are you kidding?");
        }
    }
    delete[]rank;
    return 0;
}